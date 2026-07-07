# Relatório de Desenvolvimento: API REST com NestJS, Segurança e Autenticação JWT

**Disciplina:** Programação IV (Prog-IV)
**Tecnologias Utilizadas:** TypeScript, NestJS, TypeORM, MySQL, Bcryptjs, JWT (JSON Web Token) e Insomnia.

## Introdução
Este relatório documenta o processo de desenvolvimento e configuração de uma API RESTful utilizando o framework NestJS. O objetivo principal da atividade foi construir um sistema de cadastro de usuários com alto nível de segurança, aplicando criptografia de senhas no banco de dados e implementando um sistema de login baseado em tokens JWT para autenticação.

---

## 1. Configuração da Arquitetura e Banco de Dados

A primeira etapa consistiu em preparar o ambiente de dados da aplicação, migrando de uma estrutura baseada em SQLite para um banco de dados relacional robusto (MySQL).

* **Servidor de Banco de Dados:** O ambiente local foi provisionado através do **WampServer**, que disponibilizou o serviço do MySQL na porta padrão `3306`.
* **Criação do Schema:** Utilizando o MySQL Workbench, foi executado o script DDL `CREATE DATABASE aula_08;` para instanciar a base de dados que receberia as tabelas da aplicação.
* **Integração com TypeORM:** O projeto NestJS foi atualizado para se comunicar com o MySQL. O pacote `mysql2` foi instalado via NPM para servir como driver de conexão. No arquivo principal `app.module.ts`, o módulo do TypeORM foi configurado para conectar ao banco `aula_08` com o usuário `root`, habilitando as propriedades `autoLoadEntities` e `synchronize` para garantir a geração automatizada das tabelas baseadas no código.

---

## 2. Módulo de Usuários (Criação e Criptografia)

Para gerenciar o acesso ao sistema, foi gerado um recurso completo de usuários (`npx nest generate resource usuario`), focado inteiramente na segurança dos dados armazenados.

* **Modelagem da Entidade:** O arquivo `usuario.entity.ts` foi mapeado usando os *decorators* do TypeORM (`@Entity()`, `@PrimaryGeneratedColumn()`, `@Column()`). A tabela foi configurada para armazenar `id`, `email` (com restrição `unique` para evitar cadastros duplicados) e `senha`.
* **Proteção de Dados (Hash de Senha):** Para cumprir os requisitos de segurança e evitar o armazenamento de senhas em texto puro, a biblioteca `bcryptjs` foi implementada.
* **Lógica de Negócio (Service):** No `usuario.service.ts`, o método de criação de usuário intercepta o DTO (Data Transfer Object). O sistema gera um *salt* de nível 10 e aplica a função de *hash* na senha digitada pelo usuário. Somente após essa transformação o registro é salvo definitivamente no repositório do TypeORM.
* **Exposição da Rota:** O `usuario.controller.ts` foi enxugado para expor apenas o método `POST`, garantindo uma porta de entrada limpa para novos cadastros.

---

## 3. Módulo de Autenticação (Login e Token JWT)

A etapa final do desenvolvimento *backend* foi a construção do sistema responsável por verificar credenciais e emitir credenciais de acesso temporárias. 

* **Configuração do AuthModule:** Foi gerado o módulo `auth`. Em sua estrutura, ele importou o `UsuarioModule` (para acessar o banco de dados) e o `JwtModule`. O JWT foi registrado com uma chave secreta e configurado com uma validade (expiração) de 1 hora (`expiresIn: '1h'`).
* **Validação de Credenciais:** No `auth.service.ts`, a rota de login segue um fluxo rigoroso:
  1. Busca o usuário no banco pelo e-mail fornecido.
  2. Caso o e-mail exista, utiliza o método `bcrypt.compare()` para cruzar a senha pura digitada na requisição com o *hash* irreversível salvo no banco de dados.
  3. Em caso de falha em qualquer etapa, o sistema dispara uma exceção `UnauthorizedException` (Erro 401).
* **Geração do JWT:** Com as credenciais validadas, o serviço constrói um *Payload* contendo o ID (`sub`) e o e-mail do usuário. Esse *payload* é assinado digitalmente pelo `JwtService` e devolvido ao cliente no formato de um `access_token`.

---

## 4. Testes e Validação da API

Para homologar a arquitetura, o servidor foi iniciado localmente em modo de desenvolvimento (`npm run start:dev`) e as requisições HTTP foram simuladas utilizando a plataforma **Insomnia**.

* **Teste 1: Cadastro Seguro (POST `/usuario`)**
  * **Ação:** Envio de um payload JSON contendo um e-mail de teste e uma senha simples.
  * **Resultado:** O servidor retornou o status HTTP `201 Created`. O corpo da resposta confirmou a inserção dos dados, exibindo o campo de senha completamente criptografado (ex: `$2b$10$Q8efKSe8...`), validando a eficácia do pacote bcryptjs.
  
* **Teste 2: Autenticação (POST `/auth/login`)**
  * **Ação:** Envio das mesmas credenciais exatas em texto puro.
  * **Resultado:** O sistema comparou o *hash* interno com sucesso e retornou o status HTTP `200 OK`. A resposta devolveu exclusivamente a chave `access_token` acompanhada do Token JWT completo. Esse token comprova a identidade do cliente e servirá como autorização para futuras rotas protegidas da aplicação.

## Conclusão
O desenvolvimento cumpriu todos os requisitos propostos. A API agora possui uma base sólida e escalável, utilizando as melhores práticas do mercado para manipulação de banco de dados (TypeORM), segurança de armazenamento (Hash Bcrypt) e controle de sessões *stateless* (JWT). O sistema se encontra pronto para integrações com o *frontend*.
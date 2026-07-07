# Relatório de Atividade: Introdução ao NestJS e CRUD RESTful

Este documento relata o desenvolvimento passo a passo de uma API RESTful utilizando o framework NestJS e o banco de dados SQLite, cobrindo a estruturação de módulos, integração de banco de dados e resolução de conflitos de tipagem do TypeScript.

## 1. Conceitos Teóricos Abordados

Durante a implementação, diversos conceitos arquiteturais e ferramentas exigidas na disciplina foram aplicados:

* [cite_start]**CRUD e REST:** CRUD é um acrônimo para as quatro operações fundamentais sobre dados: Create, Read, Update e Delete[cite: 252]. [cite_start]Enquanto o CRUD define *o que* será feito com os dados (a manipulação lógica), o REST é o estilo arquitetural que define *como* essas ações são organizadas e expostas em uma API através de requisições HTTP (GET, POST, PUT, DELETE)[cite: 314, 315].
* [cite_start]**DTO (Data Transfer Object):** É um objeto usado estritamente para transferir dados entre processos[cite: 241]. [cite_start]No NestJS, utilizamos os DTOs para definir a estrutura exata dos dados que o nosso sistema aceita receber nas requisições HTTP e o que ele vai devolver nas respostas[cite: 242]. Na nossa aplicação, ele garante que apenas `nome` e `idade` sejam enviados ao criar uma Pessoa.
* [cite_start]**Decorators (Decoradores):** O NestJS tem sua arquitetura fortemente baseada no uso de decoradores para manter a consistência do projeto[cite: 31]. [cite_start]Usamos marcadores com o símbolo `@` (como `@Module()`, `@Controller()`, `@Injectable()`, e `@Entity()`) para "avisar" ao framework qual é o papel de cada classe no sistema[cite: 121, 129, 414].
* [cite_start]**Swagger / OpenAPI:** Embora não tenhamos codificado o Swagger diretamente nesta atividade básica, ele é uma ferramenta essencial que se integra perfeitamente ao NestJS[cite: 60]. [cite_start]Ele serve para ler nossos Decorators e rotas, gerando automaticamente uma página web com toda a documentação da API e facilitando os testes[cite: 60, 327].

---

## 2. Estrutura de Códigos Desenvolvida

O sistema foi dividido em camadas de responsabilidade seguindo o padrão de injeção de dependências do NestJS:

### Configuração Geral
* [cite_start]**`app.module.ts`**: O módulo principal (raiz) da aplicação[cite: 129]. Nele, importamos o `PessoaModule` e configuramos a conexão global com o banco de dados via `TypeOrmModule.forRoot()`, definindo o uso do SQLite e a sincronização automática das tabelas.

### Módulo de Pessoa (`/src/pessoa`)
* [cite_start]**`pessoa.entity.ts`**: O espelho da tabela no banco de dados[cite: 238]. [cite_start]Usando o TypeORM, definimos que a classe `Pessoa` é uma `@Entity()` e que possui uma chave primária autoincrementada (`id`), além de colunas de texto e número (`nome` e `idade`)[cite: 414].
* [cite_start]**`create-pessoa.dto.ts`**: A classe de validação de transferência de dados que exige que o cliente envie os campos `nome` e `idade` corretamente no corpo da requisição[cite: 417].
* [cite_start]**`pessoa.service.ts`**: A camada que contém a regra de negócios[cite: 126, 225]. [cite_start]Injetamos o `Repository` do TypeORM no construtor para que o Service pudesse acessar o banco de dados nativamente[cite: 429, 435]. Aqui criamos os métodos `create()`, `findAll()`, `findOne()` e `remove()`.
* [cite_start]**`pessoa.controller.ts`**: A camada responsável por lidar com as solicitações HTTP de entrada[cite: 121]. [cite_start]Criamos as rotas decoradas com `@Get`, `@Post` e `@Delete` que interceptam as requisições do usuário, extraem os dados (via `@Body` ou `@Param`) e os enviam para o `PessoaService` processar[cite: 121, 448].
* **`pessoa.module.ts`**: O agrupador local. Importa o `TypeOrmModule.forFeature([Pessoa])` para liberar o acesso ao banco para a entidade específica, e declara o Controller e o Service para que o NestJS saiba amarrar todos eles.

---

## 3. Diário de Bordo: Erros Enfrentados e Soluções

Durante a configuração do ambiente no Windows 10 usando o VS Code, enfrentamos algumas particularidades e níveis altos de rigor do compilador TypeScript:

1.  **Conflito de Módulo no `tsconfig.json`:**
    * *O Problema:* A CLI do NestJS gerou o projeto baseando-se no padrão de módulos `"nodenext"`, o que causou um conflito interno imediato com a configuração predefinida de `"baseUrl": "./"`.
    * *A Solução:* A diretiva `"baseUrl"` foi removida do arquivo de configuração, alinhando-se aos padrões modernos do TypeScript e eliminando o erro de compatibilidade.

2.  **Propriedades não inicializadas na Entidade e DTO:**
    * *O Problema:* Ao declarar variáveis como `nome: string;` sem um valor padrão (como `""`), o TypeScript acusou erro de inicialização imediata.
    * *A Solução:* Utilizamos o *Non-null assertion operator* (`!`), alterando para `nome!: string;`. Isso forçou o compilador a entender que as variáveis receberiam seus valores posteriormente pelo banco de dados ou requisição externa, burlando a verificação estrita inicial.

3.  **Incompatibilidade de Tipos no TypeORM (`'sqlite'`):**
    * *O Problema:* Ao configurar o `type: 'sqlite'` no módulo raiz, o editor interpretou o valor como uma *string genérica*, quebrando a compatibilidade com a interface nativa de opções do TypeORM que exigia uma tipagem literal exata. Além disso, a variável global `__dirname` gerou conflitos no ambiente de módulos moderno.
    * *A Solução:* Removemos a necessidade de capturar diretórios manualmente trocando para a propriedade `autoLoadEntities: true`. Para resolver a leitura da string, utilizamos o "cheat code" supremo de *type assertion* (`as any`), forçando o TypeScript a ignorar a tipagem explícita e aceitar a string fornecida.

4.  **"Fantasmas" na Importação do Módulo:**
    * *O Problema:* O `pessoa.module.ts` ficou com erros de importação nas linhas referentes ao `PessoaService` e `PessoaController`.
    * *A Solução:* Este não era um erro da linguagem, mas um erro físico: estávamos tentando referenciar e amarrar dependências de arquivos que ainda não haviam sido criados no diretório. A solução foi instanciar os respectivos arquivos `.ts` e popular suas classes, restaurando o mapa de dependências do framework.
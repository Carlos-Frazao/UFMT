# Trabalho 02 - Programacao IV

Projeto pratico de integracao entre Front-end e Back-end usando a Wiki Mr. Robot criada no 1o trabalho.

Tem que ligar o servidor antes para carregar os dados

Link do site: [Acessar a Wiki Mr. Robot v-1.0.0](https://Carlos-Frazao.github.io/UFMT/3-semestre/prog-IV/trabalhos/02/frontend/)

Link do Swagger: [Clique Aqui](http://localhost:3000/api)

## Objetivo

A aplicacao deixou de usar cards estaticos no HTML e passou a consumir uma API REST feita em NestJS. O back-end gerencia personagens da serie Mr. Robot com persistencia em banco local via TypeORM/sql.js, autenticacao JWT e testes unitarios.

## Estrutura

- `backend/`: API NestJS com TypeORM, SQLite, JWT e testes.
- `frontend/`: pagina HTML/CSS/JavaScript que consome a API com `fetch`.

## Entidade principal

A entidade `Personagem` contempla os campos exigidos na especificacao:

- `titulo`: nome do personagem.
- `conteudo`: descricao textual.
- `imagem`: URL da imagem.
- `ordem`: ordem de apresentacao na interface.
- `afiliacao`: campo extra usado para manter os filtros da wiki.

## Como executar

Entre na pasta do back-end:

```bash
cd backend
npm install
npm run start:dev
```

O banco local `trabalho-02.sqlite` e criado automaticamente na primeira execucao. Depois abra o arquivo `frontend/index.html` no navegador.

## Fluxo de uso

1. Cadastre um usuario pelo formulario inicial.
2. Faca login com o mesmo e-mail e senha.
3. Apos o login, o front guarda o token JWT no `localStorage`.
4. As requisicoes para `/personagens` enviam o token no cabecalho `Authorization: Bearer`.
5. A tela permite listar, filtrar, criar, editar e remover personagens.

## Endpoints

### Usuarios

- `POST /usuarios`: cadastra um usuario.

Exemplo:

```json
{
  "email": "admin@email.com",
  "senha": "123456"
}
```

### Autenticacao

- `POST /auth/login`: valida credenciais e retorna o token JWT.

Exemplo:

```json
{
  "email": "admin@email.com",
  "senha": "123456"
}
```

### Personagens

Todas as rotas abaixo exigem JWT.

- `GET /personagens`: lista personagens ordenados por `ordem`.
- `GET /personagens/:id`: busca um personagem.
- `POST /personagens`: cria um personagem.
- `PATCH /personagens/:id`: atualiza um personagem.
- `DELETE /personagens/:id`: remove um personagem.

Exemplo de personagem:

```json
{
  "titulo": "Elliot Alderson",
  "conteudo": "Engenheiro de ciberseguranca e hacker vigilante.",
  "imagem": "https://exemplo.com/elliot.jpg",
  "ordem": 1,
  "afiliacao": "fsociety"
}
```

## Testes

Na pasta `backend`, execute:

```bash
npm test
```

Os testes cobrem regras principais do `PersonagemService` e do `AuthService`.

# Requisitos de Sistema e Ambiente (Wiki Mr. Robot)

Para executar este projeto Full-Stack (Back-end em NestJS e Front-end em Vanilla JS), o computador não precisa ser um servidor superpotente, mas exige que algumas ferramentas específicas de desenvolvimento estejam instaladas e configuradas. 

Abaixo estão os requisitos de hardware e software necessários para rodar a aplicação localmente de forma fluida.

---

## 1. Requisitos de Software (Ambiente de Desenvolvimento)

Estas são as ferramentas obrigatórias que o computador deve ter instaladas para compilar e interpretar o código do projeto:

* **Sistema Operacional:** Compatível com Windows (10 ou 11), distribuições Linux (como Debian ou Ubuntu) ou macOS.
* **Node.js:** É o motor principal do Back-end. Necessário estar na versão LTS ou superior (o projeto foi testado e compilado com sucesso na versão `v24.x`).
* **NPM (Node Package Manager):** Gerenciador de pacotes que vem instalado junto com o Node.js. É responsável por baixar e instalar as dependências do NestJS (a pasta `node_modules`).
* **Navegador Web (Browser):** Qualquer navegador moderno atualizado (Google Chrome, Mozilla Firefox, Microsoft Edge ou Brave) com suporte a requisições assíncronas (Fetch API) e armazenamento local (`localStorage`).
* **Banco de Dados (Integrado):** O projeto utiliza **SQLite**. Como é um banco de dados baseado em arquivo (serverless), **não é necessário** instalar nenhum software de banco de dados externo (como MySQL ou PostgreSQL). O próprio Node.js cria e gerencia o arquivo `.sqlite`.

## 2. Requisitos de Hardware

Embora aplicações em Node.js sejam leves, o ambiente de desenvolvimento em si (rodando o Editor de Código, o Servidor Local e o Navegador simultaneamente) consome recursos.

* **Processador (CPU):** Qualquer processador Dual-Core moderno (Intel Core i3/AMD Ryzen 3 ou equivalente) de 64 bits é perfeitamente capaz de compilar o TypeScript e rodar a API.
* **Memória RAM:**
  * **Mínimo:** 4 GB (Suficiente para rodar o servidor e o navegador, mas pode apresentar lentidão ao abrir muitas abas).
  * **Recomendado:** 8 GB ou mais (Ideal para manter o VS Code, o terminal do servidor, o navegador e a ferramenta de desenvolvedor abertos sem gargalos de memória).
* **Armazenamento:** Pelo menos **500 MB** de espaço livre em disco. A maior parte desse espaço é consumida pela pasta de bibliotecas (`node_modules`). O uso de um **SSD** é altamente recomendado em vez de um HD tradicional, pois acelera drasticamente o tempo de instalação das dependências (comando `npm install`) e a compilação do TypeScript para a pasta `dist`.

---

## 3. Ferramentas Recomendadas (Opcionais, mas ideais)

Para quem for não apenas executar, mas também dar manutenção no código:

* **Editor de Código:** Visual Studio Code (VS Code), pela sua integração nativa com TypeScript e terminais embutidos.
* **Terminal:** PowerShell (no Windows) ou Bash (no Linux/macOS) para a execução dos comandos de compilação e inicialização do servidor.

---

## 4. Checklist de Verificação Rápida

Antes de tentar rodar o projeto em qualquer máquina, o usuário pode verificar se o computador atende aos requisitos básicos abrindo o terminal e digitando os seguintes comandos:

```bash
# Verifica se o Node.js está instalado e mostra a versão
node -v

# Verifica se o gerenciador de pacotes está disponível
npm -v
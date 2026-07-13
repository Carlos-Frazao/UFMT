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

Antes de começar, certifique-se de ter as seguintes ferramentas instaladas na sua máquina:
* **[Node.js](https://nodejs.org/)** (v16 ou superior) - Para rodar o ambiente do Back-end.
* **[NPM](https://www.npmjs.com/)** - Gerenciador de pacotes (já vem embutido no Node.js).
* **Navegador Web** (Chrome, Firefox, Edge, etc.) - Para acessar o Front-end e o Swagger.

---

### Preparando e rodando o Back-end (API REST)
Abra o seu terminal, navegue até a pasta do back-end e instale as dependências:

```bash
cd backend
abaixar o node:
  sudo apt update
  sudo apt install nodejs -y
  verificar:
    node -v

abaixar o gerenciador de pacotes node:
  npm install
  verificar 
    nmp -v
    
abaixar o swagger:
  npm install --save @nestjs/swagger swagger-ui-express

ligar o servidor
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



## Checklist de Verificação Rápida

Antes de tentar rodar o projeto em qualquer máquina, o usuário pode verificar se o computador atende aos requisitos básicos abrindo o terminal e digitando os seguintes comandos:

```bash
# Verifica se o Node.js está instalado e mostra a versão
node -v

# Verifica se o gerenciador de pacotes está disponível
npm -v
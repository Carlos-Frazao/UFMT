# Relatório Técnico: Integração Full-Stack - Wiki Mr. Robot

## 1. Resumo Executivo do Projeto
Este projeto prático teve como objetivo fundamental consolidar os conceitos de desenvolvimento de software em múltiplas camadas (Full-Stack). A aplicação evoluiu de uma interface estática para um ecossistema dinâmico, integrando um Back-end robusto construído com **NestJS**, um banco de dados relacional e um Front-end reativo utilizando **HTML, CSS e JavaScript Vanilla (puro)**.

O tema escolhido para a aplicação foi uma "Wiki" do universo da série *Mr. Robot*, permitindo o gerenciamento completo (CRUD - Create, Read, Update, Delete) de personagens e suas afiliações (Fsociety, E-Corp, Dark Army, Independente).

---

## 2. Arquitetura do Back-end (O Servidor)

O servidor foi desenvolvido utilizando **NestJS**, um framework progressivo para Node.js que utiliza TypeScript por padrão. A escolha do NestJS se justifica pela sua arquitetura modular, que impõe uma organização limpa e escalável inspirada no Angular.

### Estrutura de Módulos
A aplicação foi dividida em três domínios principais:
* **UsuarioModule:** Responsável por gerenciar os dados de quem acessa o sistema. Controla a criação de novos administradores.
* **AuthModule:** O coração da segurança. Responsável por receber credenciais (e-mail e senha), validar contra o banco de dados e emitir o Token JWT (JSON Web Token).
* **PersonagemModule:** Contém a lógica de negócios para a entidade principal do projeto. Gerencia as rotas de listagem, criação, edição e remoção dos dados que populam a Wiki.

### O Banco de Dados
Foi implementado um banco de dados relacional para garantir a persistência dos dados. A entidade `Personagem` foi estruturada rigorosamente de acordo com os requisitos acadêmicos, contendo:
* **Título:** Nome do personagem (ex: Elliot Alderson).
* **Conteúdo/Texto:** A biografia e descrição do elemento.
* **Imagem:** URL apontando para a representação visual.
* **Ordem:** Valor numérico para prioridade de exibição na interface.
* **Afiliação:** Categoria do personagem, essencial para o sistema de filtros do Front-end.

---

## 3. Arquitetura do Front-end (A Interface)

A interface de usuário foi projetada para ser ágil e responsiva. O grande diferencial desta etapa foi a **remoção de todos os dados estáticos (mockados)**. O Front-end agora atua exclusivamente como um cliente que consome dados da API.

### Gerenciamento de Estado
O JavaScript foi estruturado em torno de um objeto central de estado (`const estado`), que armazena a lista atual de personagens, o filtro selecionado (ex: apenas membros da "Fsociety") e o **Token de Autenticação**.

### Comunicação Assíncrona (Fetch API)
Para garantir que a página não precise ser recarregada a cada ação, toda a comunicação com o servidor é feita de forma assíncrona utilizando a `Fetch API` nativa do JavaScript com a sintaxe `async/await`. 
A função central `requisicao()` encapsula a lógica de comunicação, tratamento de erros e injeção automática de cabeçalhos (`Headers`), reduzindo a repetição de código.

---

## 4. Segurança e Integração (Autenticação JWT)

A segurança do sistema é baseada no padrão **JWT (JSON Web Token)**. O fluxo de integração entre Front e Back-end funciona da seguinte maneira:

1.  **O Login:** O usuário insere e-mail e senha no formulário HTML.
2.  **A Validação:** O Front-end envia um `POST` para `/auth/login`. O Back-end verifica as credenciais.
3.  **A Emissão:** Se as credenciais estiverem corretas, o servidor gera um token criptografado e o devolve.
4.  **O Armazenamento:** O Front-end salva esse token no `localStorage` do navegador, garantindo que o usuário permaneça logado mesmo se fechar a aba.
5.  **O Acesso Protegido:** Para qualquer operação de CRUD (criar, editar, deletar um personagem), o Front-end anexa o token no cabeçalho da requisição (`Authorization: Bearer <token>`). O NestJS intercepta a requisição, valida o token e só então autoriza a manipulação do banco de dados.

---

## 5. Desafios Técnicos e Soluções (Troubleshooting)

O desenvolvimento de software envolve lidar com a infraestrutura e o ambiente de execução. Alguns dos principais desafios técnicos superados neste projeto demonstram um entendimento profundo do ecossistema Node.js/TypeScript:

* **Manipulação de Ambiente de SO (Windows):** Foram compreendidas as diferenças de execução de comandos em terminais nativos do Windows (PowerShell vs CMD), utilizando comandos apropriados como `Remove-Item` para limpeza de diretórios de build (`node_modules` e `dist`), em oposição a comandos Unix (`rm -rf`).
* **Ciclo de Compilação do TypeScript:** A transição do código `.ts` para `.js` apresentou desafios de cache. O compilador (`tsc`) utilizava arquivos `.tsbuildinfo` para otimizar o tempo de build, o que ocasionalmente impedia a atualização da pasta `dist`. A solução envolveu a limpeza manual do cache e o refinamento do arquivo de configuração `tsconfig.json`.
* **Resolução de Módulos (CommonJS):** O projeto exigiu a adequação do padrão de módulos para a arquitetura interna do NestJS, ajustando configurações de `"module": "nodenext"` para o padrão mais compatível `"commonjs"`, garantindo que o servidor Node.js conseguisse localizar os pontos de entrada (`main.js`) corretamente.

---

## 6. Conclusão

Este projeto cumpre rigorosamente todos os requisitos de integração Front-end e Back-end. A aplicação deixou de ser um simples documento visual estático para se tornar um software completo, protegido por autenticação moderna, com persistência de dados real e uma interface dinâmica governada por requisições HTTP assíncronas.
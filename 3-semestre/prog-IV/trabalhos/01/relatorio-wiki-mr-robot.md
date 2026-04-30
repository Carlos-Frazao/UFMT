# Relatório do Trabalho: Wiki Mr. Robot

## Identificação do Trabalho
- Curso: Programação de Computadores IV
- Disciplina: Prog-IV
- Projeto: Wiki Mr. Robot
- Arquivos principais do trabalho:
  - `wiki-mr-robot.html`
  - `script.js`
  - `estilo/style.css`

## Objetivo do Projeto
O trabalho consiste em construir uma página de tipo "wiki" com cards de personagens da série *Mr. Robot*, permitindo filtrar personagens por afiliação usando JavaScript.

## Estrutura de Arquivos
- `wiki-mr-robot.html`: página principal em HTML que contém a estrutura de navegação, personagens e o rodapé.
- `script.js`: script JavaScript responsável pela lógica de filtragem dos cards de personagens.
- `estilo/style.css`: arquivo de estilo que define cores, layout e interações visuais.

## Conteúdo HTML
A página contém:
- `<header>` com o título "Wiki Mr. Robot".
- `<nav>` com botões de filtro para as categorias: `Todos`, `Fsociety`, `E-Corp` e `Dark Army`.
- `<main>` com um formulário estático e uma seção `.lista-personagens` que reúne vários `<article>` com classe `card-personagem`.
- Cada card contém:
  - imagem do personagem (`<img>`)
  - nome do personagem (`<h3>`)
  - afiliação (`<p><strong>Afiliação:</strong> ...`)
  - descrição do personagem
- Cada card também usa o atributo `data-grupo` para indicar o grupo ao qual pertence:
  - `fsociety`
  - `ecorp`
  - `dark-army`
  - `todos`

### Personagens incluídos
A página exibe personagens da série, incluindo, entre outros:
- Elliot Alderson
- Mr. Robot
- Darlene Alderson
- Tyrell Wellick
- Whiterose
- Angela Moss
- Shayla Nico
- Fernando Vera
- Janice
- Cisco
- Otto Irving
- Leon
- Dominique DiPierro
- Grant
- Trenton
- Leslie Romero
- Mobley
- Olivia Cortez
- Lloyd Chong
- Krista Gordon
- Phillip Price
- Joanna Wellick
- Ray Heyworth
- Wang Shu
- Terry Colby
- Magda Alderson
- Edward Alderson
- Scott Knowles
- Gideon Goddard
- Oliver Parker

Além disso, a página contém um rodapé com a mensagem:
- `© 2026 Programação de Computadores IV - UFMT`

## Comportamento de JavaScript
O arquivo `script.js` faz o seguinte:
- seleciona todos os links de filtro com a classe `.filtro`
- seleciona todos os cards com a classe `.card-personagem`
- adiciona um `click` listener para cada filtro
- no clique, evita o comportamento padrão do link (`evento.preventDefault()`)
- obtém o grupo selecionado via `data-grupo`
- percorre todos os cards e mostra/esconde cada um com base no filtro:
  - se o filtro for `todos`, exibe todos os cards
  - caso contrário, exibe apenas os cards cujo `data-grupo` bate com o filtro
- a exibição é controlada modificando `card.style.display` para `flex` ou `none`

### Observação de implementação
- o JavaScript considera que os cards usam `display: flex` no CSS para manter o layout, então restaura `flex` ao mostrar um card.
- o uso de `evento.preventDefault()` garante que o clique não recarregue a página, mesmo quando o link tem `href="#"` ou `href=""`.

## Estilização CSS
O `style.css` define o visual da página:
- fundo com cor clara e degradê suave
- `header` e `footer` verdes com texto branco
- barra de navegação escura com botões claros e efeito hover
- formulário centralizado dentro do conteúdo principal
- cards de personagem com layout em `flex`, borda verde lateral e sombra
- imagens fixas de 200px de largura e ajuste com `object-fit: cover`
- transição suave ao passar o mouse nos cards (`hover` aumenta levemente o card)
- elementos de tabela estilizados, embora não haja tabela ativa na página atual

## Avaliação geral do trabalho
Pontos fortes:
- boa organização visual com cards e navegação clara
- uso de `data-grupo` para separar personagens por categoria
- funcionalidade de filtro implementada de forma simples e eficaz

Melhorias possíveis:
- padronizar todos os links de filtro para `href="#"` e manter `preventDefault()`
- adicionar responsividade para telas menores (media queries)
- incluir legendas ou títulos de grupos no layout para facilitar a leitura
- extrair dados de personagens para um array JS para tornar o HTML mais enxuto

## Conclusão
O trabalho entrega uma mini aplicação de navegação por personagens de *Mr. Robot* com filtros funcionando e um layout estilizado. A lógica do `script.js` é clara e cumpre o objetivo de mostrar apenas os cards correspondentes à categoria selecionada.

---


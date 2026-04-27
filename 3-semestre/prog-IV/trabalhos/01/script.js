// Seleciona todos os links que funcionam como filtro
const filtros = document.querySelectorAll('.filtro');

// Seleciona todos os cards de personagens
const cards = document.querySelectorAll('.card-personagem');

// Adiciona um "escutador de cliques" para cada botão de filtro
filtros.forEach(filtro => {
    filtro.addEventListener('click', function(evento) {
        // Evita que o link com href="#" faça a página pular para o topo
        evento.preventDefault();

        // Descobre qual grupo foi clicado pegando o valor do data-grupo
        const grupoSelecionado = this.getAttribute('data-grupo');

        // Passa por cada card para decidir se ele aparece ou some
        cards.forEach(card => {
            const grupoDoCard = card.getAttribute('data-grupo');

            // Se o filtro for 'todos' ou se o grupo do card bater com o botão clicado
            if (grupoSelecionado === 'todos' || grupoSelecionado === grupoDoCard) {
                // Mostra o card (como seu CSS original usa display flex, restauramos ele)
                card.style.display = 'flex'; 
            } else {
                // Esconde o card
                card.style.display = 'none';
            }
        });
    });
});
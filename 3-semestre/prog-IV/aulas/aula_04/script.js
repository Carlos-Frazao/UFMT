// Selecionando os elementos do DOM
const areaJogo = document.getElementById('area-jogo');
const displayPontos = document.getElementById('pontos');
const displayTempo = document.getElementById('tempo');
const btnIniciar = document.getElementById('btn-iniciar');

// Variáveis de controle do jogo
let pontos = 0;
let tempoRestante = 15; // Jogo dura 15 segundos
let loopCriacaoInimigos;
let loopCronometro;
let jogoRodando = false;

// Função principal para iniciar o jogo
btnIniciar.addEventListener('click', () => {
    if (jogoRodando) return; // Evita bugar clicando várias vezes
    
    // Reseta o status
    jogoRodando = true;
    pontos = 0;
    tempoRestante = 15;
    displayPontos.innerText = pontos;
    displayTempo.innerText = tempoRestante;
    areaJogo.innerHTML = ''; // Limpa a área se tiver algo
    btnIniciar.disabled = true;
    btnIniciar.innerText = "Em andamento...";

    // OBRIGATÓRIO: setInterval para gerar inimigos
    loopCriacaoInimigos = setInterval(criarInimigo, 800); // Cria um a cada 800ms

    // OBRIGATÓRIO: setInterval para o tempo diminuir
    loopCronometro = setInterval(atualizarTempo, 1000);

    // OBRIGATÓRIO: setTimeout para finalizar o jogo
    setTimeout(finalizarJogo, tempoRestante * 1000);
});

// Função para criar o inimigo no DOM
function criarInimigo() {
    // OBRIGATÓRIO: createElement
    const inimigo = document.createElement('img');
    inimigo.src = 'ana.png'; // COLOCAR SUA IMAGEM NA MESMA PASTA
    inimigo.classList.add('inimigo');

    // OBRIGATÓRIO: Math.random para posições (calcula o limite da caixa para não vazar)
    const maxX = areaJogo.clientWidth - 80; // 80 é o tamanho da imagem
    const maxY = areaJogo.clientHeight - 80;
    const posX = Math.random() * maxX;
    const posY = Math.random() * maxY;

    inimigo.style.left = `${posX}px`;
    inimigo.style.top = `${posY}px`;

    // Evento de clique no inimigo
    inimigo.onclick = function(evento) {
        pontos += 10;
        displayPontos.innerText = pontos;
        
        // Efeito visual de sangue nas coordenadas do clique
        criarEfeitoSangue(evento.offsetX + posX, evento.offsetY + posY);
        
        // Remove logo após o clique
        inimigo.remove(); 
    };

    // OBRIGATÓRIO: appendChild
    areaJogo.appendChild(inimigo);

    // Regra: inimigos desaparecem automaticamente se não clicar
    setTimeout(() => {
        if (inimigo.parentElement) {
            inimigo.remove(); // OBRIGATÓRIO: remove()
        }
    }, 1200); // Desaparece em 1.2 segundos
}

// Função para o efeito visual de clique
function criarEfeitoSangue(x, y) {
    const sangue = document.createElement('div');
    sangue.classList.add('sangue');
    sangue.style.left = `${x - 25}px`; // Centraliza a bolinha
    sangue.style.top = `${y - 25}px`;
    
    areaJogo.appendChild(sangue);

    // Remove o efeito da tela após a animação acabar
    setTimeout(() => sangue.remove(), 400);
}

// Função para atualizar o relógio
function atualizarTempo() {
    tempoRestante--;
    displayTempo.innerText = tempoRestante;
}

// Função para terminar o jogo
function finalizarJogo() {
    jogoRodando = false;
    clearInterval(loopCriacaoInimigos);
    clearInterval(loopCronometro);
    areaJogo.innerHTML = ''; // Limpa os inimigos restantes
    
    btnIniciar.disabled = false;
    btnIniciar.innerText = "Jogar Novamente";
    
    // Alerta a pontuação final
    setTimeout(() => {
        alert(`O tempo acabou! Sua pontuação final foi: ${pontos} pontos.`);
    }, 100); // Um leve delay para a tela atualizar antes do alert travar a página
}
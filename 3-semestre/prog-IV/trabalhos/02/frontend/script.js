const API_URL = 'http://localhost:3000';

const estado = {
  token: localStorage.getItem('token'),
  personagens: [],
  filtro: 'todos',
};

const areaAuth = document.getElementById('area-auth');
const areaApp = document.getElementById('area-app');
const btnSair = document.getElementById('btn-sair');
const formAuth = document.getElementById('form-auth');
const formPersonagem = document.getElementById('form-personagem');
const listaPersonagens = document.getElementById('lista-personagens');
const mensagemAuth = document.getElementById('mensagem-auth');
const mensagemPersonagem = document.getElementById('mensagem-personagem');

function headersJson() {
  return {
    'Content-Type': 'application/json',
    Authorization: `Bearer ${estado.token}`,
  };
}

async function requisicao(caminho, opcoes = {}) {
  const resposta = await fetch(`${API_URL}${caminho}`, opcoes);

  if (!resposta.ok) {
    const erro = await resposta.json().catch(() => ({}));
    throw new Error(erro.message || erro.mensagem || 'Erro na requisicao');
  }

  return resposta.json();
}

function alternarTelas() {
  const autenticado = Boolean(estado.token);
  areaAuth.classList.toggle('oculto', autenticado);
  areaApp.classList.toggle('oculto', !autenticado);
  btnSair.classList.toggle('oculto', !autenticado);

  if (autenticado) {
    carregarPersonagens();
  }
}

function renderizarPersonagens() {
  const filtrados = estado.personagens.filter((personagem) => {
    return estado.filtro === 'todos' || personagem.afiliacao === estado.filtro;
  });

  listaPersonagens.innerHTML = filtrados
    .map(
      (personagem) => `
        <article class="card-personagem">
          <div class="foto-personagem">
            <img src="${personagem.imagem}" alt="Foto de ${personagem.titulo}" />
          </div>
          <div class="info-personagem">
            <div class="cabecalho-card">
              <h3>${personagem.ordem}. ${personagem.titulo}</h3>
              <span>${formatarAfiliacao(personagem.afiliacao)}</span>
            </div>
            <p>${personagem.conteudo}</p>
            <div class="acoes-card">
              <button type="button" onclick="editarPersonagem(${personagem.id})">Editar</button>
              <button type="button" onclick="removerPersonagem(${personagem.id})">Remover</button>
            </div>
          </div>
        </article>
      `,
    )
    .join('');
}

function formatarAfiliacao(afiliacao) {
  const nomes = {
    fsociety: 'Fsociety',
    ecorp: 'E-Corp',
    'dark-army': 'Dark Army',
    independente: 'Independente',
  };

  return nomes[afiliacao] || afiliacao;
}

async function carregarPersonagens() {
  try {
    estado.personagens = await requisicao('/personagens', {
      headers: headersJson(),
    });
    renderizarPersonagens();
  } catch (erro) {
    mensagemPersonagem.textContent = erro.message;
  }
}

function limparFormularioPersonagem() {
  formPersonagem.reset();
  document.getElementById('personagem-id').value = '';
  mensagemPersonagem.textContent = '';
}

window.editarPersonagem = function editarPersonagem(id) {
  const personagem = estado.personagens.find((item) => item.id === id);

  if (!personagem) {
    return;
  }

  document.getElementById('personagem-id').value = personagem.id;
  document.getElementById('titulo').value = personagem.titulo;
  document.getElementById('conteudo').value = personagem.conteudo;
  document.getElementById('imagem').value = personagem.imagem;
  document.getElementById('ordem').value = personagem.ordem;
  document.getElementById('afiliacao').value = personagem.afiliacao;
  window.scrollTo({ top: 0, behavior: 'smooth' });
};

window.removerPersonagem = async function removerPersonagem(id) {
  try {
    await requisicao(`/personagens/${id}`, {
      method: 'DELETE',
      headers: headersJson(),
    });
    await carregarPersonagens();
    mensagemPersonagem.textContent = 'Personagem removido com sucesso.';
  } catch (erro) {
    mensagemPersonagem.textContent = erro.message;
  }
};

formAuth.addEventListener('submit', async (evento) => {
  evento.preventDefault();

  try {
    const resposta = await requisicao('/auth/login', {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify({
        email: document.getElementById('email').value,
        senha: document.getElementById('senha').value,
      }),
    });

    estado.token = resposta.access_token;
    localStorage.setItem('token', estado.token);
    mensagemAuth.textContent = '';
    alternarTelas();
  } catch (erro) {
    mensagemAuth.textContent = erro.message;
  }
});

document.getElementById('btn-cadastrar').addEventListener('click', async () => {
  try {
    await requisicao('/usuarios', {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify({
        email: document.getElementById('email').value,
        senha: document.getElementById('senha').value,
      }),
    });
    mensagemAuth.textContent = 'Usuario cadastrado. Agora clique em Entrar.';
  } catch (erro) {
    mensagemAuth.textContent = erro.message;
  }
});

formPersonagem.addEventListener('submit', async (evento) => {
  evento.preventDefault();

  const id = document.getElementById('personagem-id').value;
  const personagem = {
    titulo: document.getElementById('titulo').value,
    conteudo: document.getElementById('conteudo').value,
    imagem: document.getElementById('imagem').value,
    ordem: Number(document.getElementById('ordem').value),
    afiliacao: document.getElementById('afiliacao').value,
  };

  try {
    await requisicao(id ? `/personagens/${id}` : '/personagens', {
      method: id ? 'PATCH' : 'POST',
      headers: headersJson(),
      body: JSON.stringify(personagem),
    });

    limparFormularioPersonagem();
    await carregarPersonagens();
    mensagemPersonagem.textContent = 'Personagem salvo com sucesso.';
  } catch (erro) {
    mensagemPersonagem.textContent = erro.message;
  }
});

document.querySelectorAll('.filtro').forEach((botao) => {
  botao.addEventListener('click', () => {
    document
      .querySelectorAll('.filtro')
      .forEach((item) => item.classList.remove('ativo'));
    botao.classList.add('ativo');
    estado.filtro = botao.dataset.grupo;
    renderizarPersonagens();
  });
});

document.getElementById('btn-limpar').addEventListener('click', limparFormularioPersonagem);

btnSair.addEventListener('click', () => {
  estado.token = null;
  localStorage.removeItem('token');
  alternarTelas();
});

alternarTelas();

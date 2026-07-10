### Testar Rotas de Login com Thunder Cliente
Endereço: http://localhost:3000/auth/login
Método: POST Body: JSON
Estrutura:
    {
        "email": "Teste";
        "senha": "Teste"
    }

### Rotas Listando os Personagens
Endereço: http://localhost:3000/personagens
Método: GET Auth: Bearer

### Rotas Colocando um pessonagem no html pelo back-end
Endereço: http://localhost:3000/personagens
Método: POST
Colar o token de acesso no Auth: Bearer
Seleciona o body estrutura do JSON abaixo

    {
    "titulo": "Adicionando direto pelo backénd",
    "conteudo": "Adicionando conteudo pelo JSON direto pelo trunder",
    "imagem": "https://i.pinimg.com/1200x/28/34/c5/2834c52896d6855fa053277f89da0cb8.jpg",
    "ordem": 15,
    "afiliacao": "Independente"
    }
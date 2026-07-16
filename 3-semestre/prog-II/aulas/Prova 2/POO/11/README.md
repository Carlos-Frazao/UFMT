# Lista 11 - Sistema de Biblioteca (C++)

## 1. Objetivo do projeto
Este projeto implementa um sistema simples de gerenciamento de biblioteca em C++, usando:
- `std::vector` para armazenar livros e membros.
- arquivos texto para persistencia dos dados.
- menu interativo no terminal para operacoes de cadastro, listagem, emprestimo e devolucao.

## 2. Estrutura de arquivos
- `Livro.h` / `Livro.cpp`: classe `Livro`.
- `Membro.h` / `Membro.cpp`: classe `Membro`.
- `Biblioteca.h` / `Biblioteca.cpp`: classe `Biblioteca` (regra de negocio e persistencia).
- `main.cpp`: menu principal e interacao com usuario.
- `livros.txt`: dados dos livros.
- `membros.txt`: dados dos membros.
- `Makefile`: compilacao do projeto.

## 3. Modelagem de classes

### 3.1 Classe `Livro`
Representa um livro da biblioteca.

#### Atributos
- `isbn` (`std::string`): identificador do livro.
- `titulo` (`std::string`): titulo do livro.
- `disponivel` (`bool`): indica se pode ser emprestado.

#### Metodos
- `Livro()`:
  - construtor padrao.
- `Livro(const std::string& isbn, const std::string& titulo, bool disponivel = true)`:
  - construtor completo.
- `getISBN() const`:
  - retorna o ISBN.
- `getTitulo() const`:
  - retorna o titulo.
- `isDisponivel() const`:
  - retorna se o livro esta disponivel.
- `emprestar()`:
  - marca `disponivel = false`.
- `devolver()`:
  - marca `disponivel = true`.
- `getStatusTexto() const`:
  - retorna `"Disponivel"` ou `"Emprestado"`.
- `exibirDados() const`:
  - imprime os dados do livro no terminal.

### 3.2 Classe `Membro`
Representa um membro cadastrado na biblioteca.

#### Atributos
- `id` (`int`): identificador do membro.
- `nome` (`std::string`): nome do membro.
- `livrosEmprestados` (`std::vector<std::string>`): lista de ISBNs atualmente com o membro.

#### Metodos
- `Membro()`:
  - construtor padrao.
- `Membro(int id, const std::string& nome)`:
  - construtor com dados principais.
- `getID() const`:
  - retorna o ID.
- `getNome() const`:
  - retorna o nome.
- `getLivrosEmprestados() const`:
  - retorna copia da lista de ISBNs.
- `adicionarLivro(const std::string& isbn)`:
  - adiciona ISBN se ainda nao estiver na lista.
- `removerLivro(const std::string& isbn)`:
  - remove ISBN e retorna `true` se removeu.
- `possuiLivro(const std::string& isbn) const`:
  - verifica se membro possui aquele livro.
- `exibirDados() const`:
  - mostra ID, nome e lista de ISBNs.

### 3.3 Classe `Biblioteca`
Classe principal de regra de negocio, responsavel por:
- armazenar vetores de livros e membros.
- carregar/salvar dados em arquivos.
- executar emprestimo e devolucao validando regras.

#### Atributos
- `livros` (`std::vector<Livro>`)
- `membros` (`std::vector<Membro>`)

#### Metodos de persistencia
- `carregarLivros(const std::string& nomeArquivo)`:
  - limpa vetor.
  - le cada linha do arquivo.
  - tenta formato com `;` (`ISBN;Titulo;Status`).
  - se necessario, faz fallback para formato antigo por espacos.
  - cria objetos `Livro` e adiciona no vetor.
- `carregarMembros(const std::string& nomeArquivo)`:
  - limpa vetor.
  - le cada linha do arquivo.
  - tenta formato com `;` (`ID;Nome;ISBN1;ISBN2...`).
  - se necessario, faz fallback para formato antigo por espacos.
  - cria objetos `Membro` e adiciona no vetor.
- `gravarLivros(const std::string& nomeArquivo) const`:
  - grava todos os livros no formato `ISBN;Titulo;Status`.
- `gravarMembros(const std::string& nomeArquivo) const`:
  - grava todos os membros no formato `ID;Nome;ISBN1;ISBN2...`.

#### Metodos de cadastro/listagem
- `registrarLivro(const Livro& livro)`:
  - percorre vetor com `for` e impede ISBN duplicado.
  - retorna `true` se cadastrou.
- `registrarMembro(const Membro& membro)`:
  - percorre vetor com `for` e impede ID duplicado.
  - retorna `true` se cadastrou.
- `listarLivros() const`:
  - exibe todos os livros.
- `listarMembros() const`:
  - exibe todos os membros.

#### Metodos de emprestimo/devolucao
- `emprestarLivro(const std::string& isbn, int idMembro)`:
  - busca livro por ISBN (com laço `for`).
  - verifica se existe.
  - verifica disponibilidade.
  - busca membro por ID (com laço `for`).
  - verifica se existe.
  - marca livro como emprestado.
  - adiciona ISBN na lista do membro.
- `devolverLivro(const std::string& isbn, int idMembro)`:
  - busca membro por ID.
  - verifica se existe.
  - valida se ele possui o livro.
  - busca livro por ISBN.
  - remove ISBN do membro.
  - marca livro como disponivel.

## 4. Fluxo geral do programa (`main.cpp`)
1. Cria um objeto `Biblioteca`.
2. Define nomes dos arquivos: `livros.txt` e `membros.txt`.
3. Carrega dados do disco para memoria.
4. Entra em loop de menu:
   - 1 Registrar livro
   - 2 Registrar membro
   - 3 Listar livros
   - 4 Listar membros
   - 5 Emprestar livro
   - 6 Devolver livro
   - 7 Sair
5. Em operacoes que alteram estado (cadastro, emprestimo, devolucao), grava os arquivos.
6. Ao sair, grava novamente para garantir persistencia final.

## 5. Formato dos arquivos de dados

### `livros.txt`
Formato:
```
ISBN;Titulo;Disponivel|Emprestado
```

Exemplo:
```
ISBN1;Titulo1;Disponivel
ISBN2;Titulo2;Emprestado
ISBN3;Titulo3;Disponivel
```

### `membros.txt`
Formato:
```
ID;Nome;ISBN1;ISBN2;...
```

Exemplo:
```
1;Joao;ISBN2
2;Maria
3;Pedro;ISBN3
```

Observacao:
- O formato com `;` foi adotado para suportar nomes e titulos com espacos.
- O carregamento ainda aceita formato antigo por espacos como compatibilidade.

## 6. Como compilar e executar

### Usando Makefile
```bash
make
./biblioteca
```

No Windows (gerando `.exe`):
```bash
make
biblioteca.exe
```

### Compilacao manual
```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp Livro.cpp Membro.cpp Biblioteca.cpp -o biblioteca
```

## 7. Regras importantes implementadas
- Busca de livros e membros feita por varredura em vetor com laço `for` (sem `std::map`).
- Nao permite ISBN duplicado no cadastro.
- Nao permite ID duplicado no cadastro.
- Emprestimo so ocorre se:
  - livro existe
  - livro esta disponivel
  - membro existe
- Devolucao so ocorre se:
  - membro existe
  - membro realmente possui o livro
  - livro existe

## 8. Resumo final
O projeto atende os requisitos da Lista 11 com:
- orientacao a objetos (3 classes principais),
- persistencia em arquivos texto,
- menu funcional em terminal,
- validacoes de negocio para emprestimo/devolucao,
- compilacao via `Makefile`.

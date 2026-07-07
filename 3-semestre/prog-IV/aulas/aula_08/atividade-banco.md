# Atividade: Banco de Dados com MySQL

Esta documentação contém a resolução do exercício prático da Aula 08, que consiste em criar a tabela da entidade `Pessoa` (desenvolvida na aula 07), inserir registros e realizar uma consulta, utilizando a linguagem SQL.

## 1. Criação da Tabela (Comando DDL)
[cite_start]O comando `CREATE TABLE` é utilizado para definir a estrutura da tabela no banco de dados[cite: 681].
* [cite_start]O campo `id` foi definido como `INT` (número inteiro) [cite: 618][cite_start], `AUTO_INCREMENT` e `PRIMARY KEY` (chave primária, garantindo que não haverá duplicidade)[cite: 668, 669].
* [cite_start]O campo `nome` foi definido como `VARCHAR(255)` (texto de tamanho variável)[cite: 631].
* O campo `idade` foi definido como `INT`.

```sql
CREATE TABLE Pessoa (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(255) NOT NULL,
    idade INT NOT NULL
);
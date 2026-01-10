# Exercício 04: Sed is for losers

## Objetivo
Criar uma versão simplificada do comando `sed` que substitui todas as ocorrências de uma string `s1` por outra string `s2` em um arquivo específico.
O desafio principal é fazer isso **sem utilizar a função `std::string::replace`**, que é proibida pelo exercício.

## Conceitos Chave

### 1. Manipulação de Arquivos (File I/O)
Utilizamos as classes da biblioteca fstream:
- **`std::ifstream`**: Para abrir e ler o arquivo de entrada.
  - Método `is_open()` verifica se o arquivo existe e pode ser lido.
  - Lemos todo o conteúdo para um buffer (usando `std::stringstream`) para facilitar a manipulação.
- **`std::ofstream`**: Para criar e escrever no arquivo de saída (`<filename>.replace`).

### 2. A Lógica de Substituição Manual
Como não podemos usar a função pronta `replace`, implementamos nossa própria lógica de "encontrar e reconstruir":

1.  Começamos com uma string vazia `result` e a string original `content`.
2.  Usamos `content.find(s1, pos)` para encontrar onde está a próxima ocorrência de `s1` a partir da posição atual `pos`.
3.  **Loop**: Enquanto encontrarmos `s1`:
    - Copiamos tudo que está antes de `s1` (desde a última posição `pos` até o início do match) para o `result`.
    - Adicionamos a nova string `s2` ao `result`.
    - Avançamos nosso cursor `pos` para logo depois de `s1`.
    - Procuramos a próxima ocorrência.
4.  Ao final do loop, copiamos o restante do texto (que não contém mais `s1`) para `result`.

### Exemplo
Texto: `"Olá Mundo Mundo"`, trocar `"Mundo"` por `"42"`

1. `pos = 0`. Encontra "Mundo" no índice 4.
   - Apende "Olá " (0 ao 4). **Result: "Olá "**
   - Apende "42". **Result: "Olá 42"**
   - Atualiza `pos` para 9 (fim do primeiro "Mundo").
2. Encontra próximo "Mundo" no índice 10.
   - Apende " " (9 ao 10). **Result: "Olá 42 "**
   - Apende "42". **Result: "Olá 42 42"**
   - Atualiza `pos` para 15.
3. Não encontra mais nada.
   - Apende restante (nada).
4. Grava **"Olá 42 42"** no arquivo `.replace`.

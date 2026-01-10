# Exercício 02: HI THIS IS BRAIN

## Objetivo
Este exercício tem como objetivo desmistificar o conceito de **Referências** em C++, comparando-as com os já conhecidos **Ponteiros**.

## Conceitos Chave

### 1. Variável Comum
```cpp
std::string str = "HI THIS IS BRAIN";
```
- É o objeto em si, armazenado na memória (Stack).
- Tem um endereço de memória único (`&str`).

### 2. Ponteiro (`*`)
```cpp
std::string* stringPTR = &str;
```
- É uma variável que **armazena um endereço de memória**.
- Para acessar o valor original, precisamos **dereferenciar** o ponteiro usando `*stringPTR`.
- Pode ser reatribuído para apontar para outro lugar (ou para `NULL`).

### 3. Referência (`&`)
```cpp
std::string& stringREF = str;
```
- É um **apelido** (alias) para uma variável já existente.
- **Não** é uma nova variável com seu próprio armazenamento da mesma forma que um ponteiro; ela *é* a variável original com outro nome.
- Para acessar o valor, usamos a referência diretamente (`stringREF`), sem precisar de `*`.
- **Deve** ser inicializada na criação e **nunca** pode ser nula ou reatribuída para referenciar outra variável.

## Entendendo a Saída do Código

Quando você executa o programa, você vê que:

1.  **Endereços**:
    - `&str`: Endereço de `str`.
    - `stringPTR`: Valor armazenado no ponteiro (que é o endereço de `str`).
    - `&stringREF`: Endereço da referência (que, como é um apelido, é o MESMO endereço de `str`).
    - **Resultado**: Os três endereços são IDÊNTICOS.

2.  **Valores**:
    - `str`: "HI THIS IS BRAIN".
    - `*stringPTR`: "HI THIS IS BRAIN" (Acessado indiretamente).
    - `stringREF`: "HI THIS IS BRAIN" (Acessado diretamente pelo apelido).

## Resumo
| Característica | Ponteiro (`*`) | Referência (`&`) |
|----------------|----------------|------------------|
| Pode ser nulo? | Sim (`NULL` or `nullptr`) | Não |
| Pode mudar o alvo? | Sim | Não (eterno vínculo) |
| Sintaxe de acesso | `*ptr` (dereferência) | `ref` (direto) |
| O que é? | Variável que guarda endereço | Apelido para um objeto |

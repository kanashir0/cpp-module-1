# Exercício 05: Harl 2.0

## Objetivo
O objetivo deste exercício é eliminar o uso de longas cadeias de `if / else if / else` para selecionar qual função executar com base em uma string.
A técnica exigida é o uso de **Ponteiros para Funções Membro** (Pointers to Member Functions).

## Conceitos Chave

### 1. Ponteiro De Função vs Ponteiro de Função Membro
Um ponteiro de função normal (`void (*ptr)(void)`) aponta para uma função estática ou global.
Um **ponteiro de função membro** precisa saber a qual classe pertence, pois funções membro precisam de uma instância (`this`) para serem chamadas.

**Sintaxe:**
```cpp
void (NomeDaClasse::*NomeDoPonteiro)(Argumentos);
```
No nosso caso:
```cpp
void (Harl::*ptr)(void);
```

### 2. Array de Ponteiros
Para mapear os níveis "DEBUG", "INFO", etc. para suas respectivas funções, criamos dois arrays paralelos (ou um array de pares/structs):
1.  Um array de strings com os nomes dos níveis.
2.  Um array de ponteiros para as funções correspondentes.

```cpp
std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
void (Harl::*funcs[])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
```

### 3. Chamando a Função
Para chamar uma função através desse ponteiro, precisamos de uma instância específica. Dentro da classe, usamos `this`.
A sintaxe é um pouco exótica:
```cpp
(this->*funcs[i])();
```
- `this`: A instância atual.
- `->*`: O operador específico para acessar um ponteiro de membro através de um ponteiro de instância.
- `funcs[i]`: O ponteiro para a função membro que queremos chamar.
- `()`: Os parênteses finais para efetivamente executar a função.

## Vantagens
- **Código Limpo**: Elimina a "floresta" de `if/else`.
- **Escalabilidade**: Para adicionar um novo nível, basta adicionar a string e o ponteiro nos arrays, sem mexer na lógica de despacho.
- **Performance**: Em escalas maiores, um lookup table (tabela de busca) é geralmente mais rápido que comparar strings sequencialmente em um if/else gigante (embora com 4 itens a diferença seja irrelevante, o conceito é o foco).

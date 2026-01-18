# Exercício 01: Moar brainz!

## Objetivo
Este exercício foca na alocação de **múltiplos objetos** de uma vez (arrays de objetos) na memória Heap e como gerenciá-los corretamente.

## Conceitos Chave

### 1. Alocação de Array (`new[]`)
Diferente do exercício anterior onde alocamos um único zumbi, aqui precisamos alocar `N` zumbis de uma vez.
```cpp
Zombie* horde = new Zombie[N];
```
- **O Desafio**: Em C++98, quando você aloca um array de objetos, a linguagem invoca automaticamente o **construtor padrão** (sem parâmetros) para cada objeto do array. Não é possível passar argumentos (como o nome) diretamente na alocação do array de forma simples.
- **A Solução**: Tivemos que adaptar a classe `Zombie` para ter:
    1.  Um **Construtor Padrão** (`Zombie()`) que não recebe parâmetros, para permitir a criação do array.
    2.  Um método `setName` (setter) para definir o nome *após* a criação.

### 2. Inicialização Tardia
Como os objetos nascem "sem nome" (ou com nome padrão) devido ao construtor padrão, precisamos iterar sobre o array para configurá-los:
```cpp
for (int i = 0; i < N; i++) {
    horde[i].setName(name);
}
```

### 3. Desalocação de Array (`delete[]`)
Este é o ponto mais crítico do exercício. Se você alocou com `new[]`, **DEVE** desalocar com `delete[]`.
```cpp
delete [] horde;
```
- **Por que `[]`?**: O `[]` diz ao compilador "isso é um array". O compilador então olha quantos objetos existem naquele array e chama o **destrutor para CADA UM deles** antes de liberar a memória.
- **Erro comum**: Se você usar apenas `delete horde` (sem colchetes), o comportamento é indefinido, mas geralmente apenas o primeiro zumbi seria destruído corretamente, causando vazamento de memória e comportamento incorreto para os outros.

## Estrutura dos Arquivos (`src/`)

- **`Zombie.cpp`**: Contém a lógica da classe. Note a adição de `Zombie::Zombie()` e `Zombie::setName()`.
- **`zombieHorde.cpp`**: Contém a função que aloca o array, configura os nomes e retorna o ponteiro para o primeiro elemento.
- **`main.cpp`**:
    1.  Chama `zombieHorde` para criar 5 zumbis.
    2.  Anuncia todos eles (provando que estão vivos e nomeados).
    3.  Chama `delete []` para limpar tudo (você verá 5 mensagens de destruição).

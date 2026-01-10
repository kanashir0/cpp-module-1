# C++ - Módulo 01

## Alocação de memória, ponteiros para membros,

## referências e declarações switch

```
Preâmbulo:
Este documento contém os exercícios do Módulo 01 dos módulos de C++.
```
```
Versão: 11.
```

## Sumário

- I Introdução
- II Regras gerais
- III Instruções de IA
- IV Exercício 00: BraiiiiiiinnnzzzZ
- V Exercício 01: Moar brainz!
- VI Exercício 02: HI THIS IS BRAIN
- VII Exercício 03: Unnecessary violence
- VIII Exercício 04: Sed is for losers
- IX Exercício 05: Harl 2.0
- X Exercício 06: Harl filter
- XI Entrega e avaliação por pares


# Capítulo I

# Introdução

_C++ é uma linguagem de programação de propósito geral criada por Bjarne Stroustrup
como uma extensão da linguagem de programação C, ou "C com Classes"(fonte: Wikipe-
dia)._

O objetivo destes módulos é apresentar a você a **Programação Orientada a Ob-
jetos**. Este será o ponto de partida da sua jornada em C++. Muitas linguagens são
recomendadas para aprender POO. Escolhemos C++ porque ela deriva do seu velho
amigo, C. Como esta é uma linguagem complexa, e para manter as coisas simples, seu
código estará em conformidade com o padrão C++98.
Estamos cientes de que o C++ moderno é muito diferente em muitos aspectos. Então,
se você quiser se tornar um desenvolvedor C++ proficiente, cabe a você ir mais longe
após o 42 Common Core!


# Capítulo II

# Regras gerais

**Compilação**

- Compile seu código com c++ e as flags -Wall -Wextra -Werror
- Seu código ainda deve compilar se você adicionar a flag -std=c++

```
Formatação e convenções de nomenclatura
```
- Os diretórios dos exercícios serão nomeados desta forma: ex00, ex01, ... ,
    exn
- Nomeie seus arquivos, classes, funções, funções membro e atributos conforme exi-
    gido nas diretrizes.
- Escreva os nomes das classes no formato **UpperCamelCase**. Arquivos contendo
    código de classe sempre serão nomeados de acordo com o nome da classe. Por
    exemplo:
    NomeDaClasse.hpp/NomeDaClasse.h, NomeDaClasse.cpp, ou NomeDaClasse.tpp.
    Então, se você tiver um arquivo de cabeçalho contendo a definição de uma classe
    "ParedeDeTijolo"representando uma parede de tijolos, seu nome será ParedeDeTijolo.hpp.
- A menos que especificado de outra forma, cada mensagem de saída deve terminar
    com um caractere de nova linha e ser exibida na saída padrão.
- _Adeus Norminette!_ Nenhum estilo de codificação é imposto nos módulos C++.
    Você pode seguir o seu favorito. Mas lembre-se que o código que seus avaliadores
    não conseguem entender é um código que eles não podem avaliar. Faça o seu melhor
    para escrever um código limpo e legível.

```
Permitido/Proibido
```
```
Você não está mais programando em C. É hora de C++! Portanto:
```
- Você pode usar quase tudo da biblioteca padrão. Assim, em vez de se ater ao que
    você já conhece, seria inteligente usar as versões em C++ das funções C que você
    está acostumado o máximo possível.


C++ - Módulo 01

```
Alocação de memória, ponteiros para membros,
referências e declarações switch
```
- No entanto, você não pode usar nenhuma outra biblioteca externa. Isso significa
    que bibliotecas C++11 (e formas derivadas) e Boost são proibidas. As seguintes
    funções também são proibidas: *printf(), *alloc() e free(). Se você usá-las,
    sua nota será 0 e pronto.
- Observe que, a menos que explicitamente indicado de outra forma, as palavras-
    chave using namespace <ns_name> e friend são proibidas. Caso contrário, sua
    nota será -42.
- **Você só pode usar a STL nos Módulos 08 e 09.** Isso significa: nenhum
    **Contêiner** (vector/list/map, e assim por diante) e nenhum **Algoritmo** (qualquer
    coisa que exija a inclusão do cabeçalho <algorithm>) até lá. Caso contrário, sua
    nota será -42.

```
Alguns requisitos de design
```
- Vazamento de memória ocorre em C++ também. Quando você aloca memória
    (usando a palavra-chave new), você deve evitar **vazamentos de memória**.
- Do Módulo 02 ao Módulo 09, suas classes devem ser projetadas na **Forma Canô-**
    **nica Ortodoxa, exceto quando explicitamente indicado de outra forma**.
- Qualquer implementação de função colocada em um arquivo de cabeçalho (exceto
    para modelos de função) significa 0 para o exercício.
- Você deve ser capaz de usar cada um de seus cabeçalhos independentemente de
    outros. Portanto, eles devem incluir todas as dependências de que precisam. No
    entanto, você deve evitar o problema de inclusão dupla adicionando **proteções de**
    **inclusão**. Caso contrário, sua nota será 0.

```
Leia-me
```
- Você pode adicionar alguns arquivos adicionais se precisar (ou seja, para dividir seu
    código). Como essas atribuições não são verificadas por um programa, sinta-se à
    vontade para fazê-lo, desde que você entregue os arquivos obrigatórios.
- Às vezes, as diretrizes de um exercício parecem curtas, mas os exemplos podem
    mostrar requisitos que não estão explicitamente escritos nas instruções.
- Leia cada módulo completamente antes de começar! Sério, faça isso.
- Por Odin, por Thor! Use seu cérebro!!!

```
Em relação ao Makefile para projetos C++, as mesmas regras do C se
aplicam (consulte o capítulo Norma sobre o Makefile).
```

C++ - Módulo 01

```
Alocação de memória, ponteiros para membros,
referências e declarações switch
```
```
Você terá que implementar muitas classes. Isso pode parecer tedioso,
a menos que você seja capaz de criar scripts para seu editor de texto
favorito.
```
```
Você tem uma certa liberdade para completar os exercícios. No
entanto, siga as regras obrigatórias e não seja preguiçoso. Você
perderia muitas informações úteis! Não hesite em ler sobre conceitos
teóricos.
```

# Capítulo IV

# Exercício 00: BraiiiiiiinnnzzzZ

```
Exercice : 00
```
```
BraiiiiiiinnnzzzZ
Pasta de entrega : ex 00 /
Arquivos para entregar : Makefile, main.cpp, Zombie.{h, hpp}, Zombie.cpp,
newZombie.cpp, randomChump.cpp
Funções não permitidas : Nenhuma
```
Primeiro, implemente uma classe **Zombie**. Ela tem um atributo string privado name.
Adicione uma função membro void announce( void ); à classe Zombie. Zumbis se
anunciam da seguinte forma:

```
<name>: BraiiiiiiinnnzzzZ...
```
Não imprima os colchetes angulares (< e >). Para um zumbi chamado Foo, a men-
sagem seria:

```
Foo: BraiiiiiiinnnzzzZ...
```
```
Então, implemente as duas funções seguintes:
```
- Zombie* newZombie( std::string name );
    Esta função cria um zumbi, dá um nome a ele e o retorna para que você possa
    usá-lo fora do escopo da função.
- void randomChump( std::string name );
    Esta função cria um zumbi, dá um nome a ele e o faz se anunciar.

Agora, qual é o objetivo real do exercício? Você tem que determinar em qual caso é
melhor alocar zumbis na stack ou no heap.

Zumbis devem ser destruídos quando você não precisar mais deles. O destrutor deve
imprimir uma mensagem com o nome do zumbi para fins de depuração.


# Capítulo V

# Exercício 01: Moar brainz!

```
Exercice : 01
```
```
Moar brainz!
Pasta de entrega : ex 01 /
Arquivos para entregar : Makefile, main.cpp, Zombie.{h, hpp}, Zombie.cpp,
zombieHorde.cpp
Funções não permitidas : Nenhuma
```
```
Hora de criar uma horda de Zumbis!
```
```
Implemente a seguinte função no arquivo apropriado:
```
```
Zombie* zombieHorde( int N, std::string name );
```
Ela deve alocar N objetos Zombie em uma única alocação. Então, ela deve inicializar
os zumbis, dando a cada um deles o nome passado como um parâmetro. A função retorna
um ponteiro para o primeiro zumbi.
Implemente seus próprios testes para garantir que sua função zombieHorde() funci-
one como esperado. Tente chamar announce() para cada um dos zumbis.

Não se esqueça de usar delete para desalocar todos os zumbis e verificar se há **va-
zamentos de memória**.


# Capítulo VI

# Exercício 02: HI THIS IS BRAIN

```
Exercice : 02
```
```
HI THIS IS BRAIN
Pasta de entrega : ex 02 /
Arquivos para entregar : Makefile, main.cpp
Funções não permitidas : Nenhuma
```
```
Escreva um programa que contenha:
```
- Uma variável string inicializada com "HI THIS IS BRAIN".
- stringPTR: um ponteiro para a string.
- stringREF: uma referência à string.

```
Seu programa deve imprimir:
```
- O endereço de memória da variável string.
- O endereço de memória mantido por stringPTR.
- O endereço de memória mantido por stringREF.

```
E então:
```
- O valor da variável string.
- O valor apontado por stringPTR.
- O valor apontado por stringREF.

É isso — sem truques. O objetivo deste exercício é desmistificar as referências, que
podem parecer completamente novas. Embora existam algumas pequenas diferenças, esta
é simplesmente outra sintaxe para algo que você já faz: manipulação de endereços.


# Capítulo VII

# Exercício 03: Unnecessary violence

```
Exercice : 03
```
```
Violência desnecessária
Pasta de entrega : ex 03 /
Arquivos para entregar : Makefile, main.cpp, Weapon.{h, hpp}, Weapon.cpp,
HumanA.{h, hpp}, HumanA.cpp, HumanB.{h, hpp}, HumanB.cpp
Funções não permitidas : Nenhuma
```
```
Implemente uma classe Weapon que tenha:
```
- Um atributo privado type, que é uma string.
- Uma função membro getType() que retorna uma referência constante a type.
- Uma função membro setType() que define type usando o novo valor passado como
    um parâmetro.

Agora, crie duas classes: **HumanA** e **HumanB**. Ambas têm uma Weapon e um name.
Elas também têm uma função membro attack() que exibe (sem os colchetes angulares):

```
<name> attacks with their <tipo de arma>
```
```
HumanA e HumanB são quase idênticas, exceto por esses dois pequenos detalhes:
```
- Enquanto **HumanA** recebe a Weapon em seu construtor, **HumanB** não.
- **HumanB** pode **nem sempre** ter uma arma, enquanto **HumanA** sempre **sempre**
    estará armado.


```
C++ - Módulo 01
```
```
Alocação de memória, ponteiros para membros,
referências e declarações switch
```
Se sua implementação estiver correta, a execução do seguinte código imprimirá um
ataque com "crude spiked club"seguido por um segundo ataque com "some other type of
club"para ambos os casos de teste:

```
int main()
{
{
Weapon club = Weapon("crude spiked club");
HumanA bob("Bob", club);
bob.attack();
club.setType("some other type of club");
bob.attack();
}
{
Weapon club = Weapon("crude spiked club");
HumanB jim("Jim");
jim.setWeapon(club);
jim.attack();
club.setType("some other type of club");
jim.attack();
}
return 0;
}
```
```
Não se esqueça de verificar se há vazamentos de memória.
```
```
Em qual caso você acha que seria melhor usar um ponteiro para Weapon?
E uma referência para Weapon? Por quê? Pense sobre isso antes de
começar este exercício.
```

# Capítulo VIII

# Exercício 04: Sed is for losers

```
Exercice : 04
```
```
Sed é para perdedores
Pasta de entrega : ex 04 /
Arquivos para entregar : Makefile, main.cpp, *.cpp, *.{h, hpp}
Funções não permitidas : std::string::replace
```
Crie um programa que receba três parâmetros na seguinte ordem: um nome de arquivo
e duas strings, s1 e s2.
Ele deve abrir o arquivo <nome do arquivo> e copiar seu conteúdo para um novo
arquivo
<nome do arquivo>.replace, substituindo cada ocorrência de s1 com s2.

Usar funções de manipulação de arquivos C é proibido e será considerado trapaça.
Todas as funções membro da classe std::string são permitidas, exceto replace. Use-
as com sabedoria!

Claro, lide com entradas e erros inesperados. Você deve criar e entregar seus próprios
testes para garantir que seu programa funcione como esperado.


# Capítulo IX

# Exercício 05: Harl 2.

```
Exercice : 05
```
```
Harl 2.
Pasta de entrega : ex 05 /
Arquivos para entregar : Makefile, main.cpp, Harl.{h, hpp}, Harl.cpp
Funções não permitidas : Nenhuma
```
Você conhece Harl? Todos nós conhecemos, não é? Caso você não conheça, encontre
abaixo o tipo de comentários que Harl faz. Eles são classificados por níveis:

- Nível " **DEBUG** ": Mensagens de depuração contêm informações contextuais. Elas
    são usadas principalmente para diagnóstico de problemas.
    Exemplo: _"Eu amo ter bacon extra para o meu hambúrguer 7XL-duplo-queijo-triplo-_
    _picles-ketchup-especial. Eu realmente amo!"_
- Nível " **INFO** ": Estas mensagens contêm informações extensas. Elas são úteis para
    rastrear a execução do programa em um ambiente de produção.
    Exemplo: _"Eu não acredito que adicionar bacon extra custa mais dinheiro. Vocês_
    _não colocaram bacon suficiente no meu hambúrguer! Se vocês tivessem colocado, eu_
    _não estaria pedindo por mais!"_
- Nível " **WARNING** ": Mensagens de aviso indicam um problema potencial no sis-
    tema. No entanto, ele pode ser tratado ou ignorado.
    Exemplo: _"Eu acho que mereço ter bacon extra de graça. Eu venho aqui há anos,_
    _enquanto você começou a trabalhar aqui apenas no mês passado."_
- Nível " **ERROR** ": Estas mensagens indicam que ocorreu um erro irrecuperável.
    Este é geralmente um problema crítico que requer intervenção manual.
    Exemplo: _"Isto é inaceitável! Eu quero falar com o gerente agora."_


```
C++ - Módulo 01
```
```
Alocação de memória, ponteiros para membros,
referências e declarações switch
```
Você vai automatizar Harl. Não será difícil, pois ele sempre diz as mesmas coisas.
Você tem que criar uma classe **Harl** com as seguintes funções membro privadas:

- void debug( void );
- void info( void );
- void warning( void );
- void error( void );

**Harl** também tem uma função membro pública que chama as quatro funções membro
acima, dependendo do nível passado como um parâmetro:

```
void complain( std::string level );
```
O objetivo deste exercício é usar **ponteiros para funções membro**. Isto não é uma
sugestão. Harl tem que reclamar sem usar uma floresta de if/else if/else. Ele não pensa
duas vezes!

Crie e entregue testes para mostrar que Harl reclama muito. Você pode usar os
exemplos de comentários listados acima no assunto ou escolher usar comentários de sua
autoria.

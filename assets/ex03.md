# Exercício 03: Unnecessary violence

## Objetivo
O objetivo deste exercício é demonstrar na prática quando usar **Ponteiros** (`*`) e quando usar **Referências** (`&`) como membros de uma classe em C++.

## Lógica e Design

A decisão de design foi baseada nas restrições impostas pelo exercício sobre a relação entre o Humano e sua Arma.

### 1. HumanA: A Referência (`Weapon&`)
> "HumanA sempre estará armado."

Para `HumanA`, usamos uma **Referência**:
```cpp
class HumanA {
    Weapon& _weapon; // Referência
    // ...
};
```
- **Por que?**:
    1.  **Garantia de Existência**: Uma referência em C++ **precisa** ser inicializada. Isso força o construtor a receber uma `Weapon` válida.
    2.  **Impossível ser Nulo**: Uma referência não pode ser nula. Isso garante a regra de que ele "sempre estará armado".
    3.  **Sintaxe**: Permite usar `_weapon.getType()` diretamente.

- **Inicialização**: Como é uma referência, ela deve ser inicializada na **Lista de Inicialização** do construtor:
  ```cpp
  HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {}
  ```

### 2. HumanB: O Ponteiro (`Weapon*`)
> "HumanB pode nem sempre ter uma arma."

Para `HumanB`, usamos um **Ponteiro**:
```cpp
class HumanB {
    Weapon* _weapon; // Ponteiro
    // ...
};
```
- **Por que?**:
    1.  **Nulabilidade**: Um ponteiro pode ser definido como `NULL` (ou `nullptr`). Isso permite representar o estado "sem arma".
    2.  **Reatribuição Tardia**: O exercício pede que `HumanB` não receba a arma no construtor, mas sim via `setWeapon()`. Ponteiros são facilmente reatribuídos a qualquer momento.

- **Precaução**: Como o ponteiro pode ser nulo, precisamos verificar antes de usar:
  ```cpp
  void HumanB::attack() {
      if (this->_weapon != NULL) {
          // Ataca
      } else {
          // Mensagem de erro ou nada
      }
  }
  ```

## Resumo da Escolha

| Situação | Use Referência (`&`) | Use Ponteiro (`*`) |
|----------|-----------------------|--------------------|
| O objeto deve existir sempre? | **Sim** | Não |
| Pode ser `NULL`? | Não | **Sim** |
| Precisa mudar o objeto apontado? | Não (vínculo eterno) | **Sim** |
| Exemplo neste exercício | `HumanA` (Sempre Armado) | `HumanB` (Opcionalmente Armado) |

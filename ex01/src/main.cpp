#include "Zombie.hpp"

#define NUM_ZOMBIES 5

int main(void) {
    std::cout << "--- Creating Horde of " << NUM_ZOMBIES << " zombies ---" << std::endl;
    Zombie* horde = zombieHorde(NUM_ZOMBIES, "HordeMember");

    if (horde == NULL) {
        std::cerr << "Allocation failed" << std::endl;
        return 1;
    }

    std::cout << "\n--- Announcing Horde ---" << std::endl;
    for (int i = 0; i < NUM_ZOMBIES; i++) {
        horde[i].announce();
    }

    std::cout << "\n--- Deleting Horde ---" << std::endl;
    delete [] horde;

    return 0;
}

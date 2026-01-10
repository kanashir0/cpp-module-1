#include "Zombie.hpp"

int main(void) {
    std::cout << "--- Stack allocation (randomChump) ---" << std::endl;
    randomChump("ChumpStack");

    std::cout << "\n--- Heap allocation (newZombie) ---" << std::endl;
    Zombie* heapZombie = newZombie("HeapZ");
    heapZombie->announce();
    delete heapZombie;

    return 0;
}

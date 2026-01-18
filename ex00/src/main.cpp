#include "Zombie.hpp"

int main(void) {
    std::cout << "--- Stack allocation (randomChump) ---" << std::endl;
    randomChump("StackZombie");

    std::cout << "\n--- Heap allocation (newZombie) ---" << std::endl;
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;

    return 0;
}

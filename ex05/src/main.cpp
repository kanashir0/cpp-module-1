#include "Harl.hpp"

int main() {
    Harl harl;

    std::cout << "TESTING DEBUG:" << std::endl;
    harl.complain("DEBUG");
    
    std::cout << "\nTESTING INFO:" << std::endl;
    harl.complain("INFO");
    
    std::cout << "\nTESTING WARNING:" << std::endl;
    harl.complain("WARNING");
    
    std::cout << "\nTESTING ERROR:" << std::endl;
    harl.complain("ERROR");
    
    std::cout << "\nTESTING INVALID:" << std::endl;
    harl.complain("INVALID"); // Should do nothing

    return 0;
}

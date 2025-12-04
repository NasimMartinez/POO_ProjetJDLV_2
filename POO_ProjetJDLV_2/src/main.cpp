#include "../lib/common/libs.h"
#include "../lib/Manager/manager.h"
#include "../lib/testBlocK/testBlock.h"

int main() {
    /*
    Manager manager;
    manager.run();
    */
    std::cout << "=== Lancement des tests unitaires ===" << std::endl;

    testBlockStable();
    return 0;
}
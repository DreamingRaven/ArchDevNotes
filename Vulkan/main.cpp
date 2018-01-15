// GeorgeRaven:18/01/13 (yy/mm/dd)
#include <iostream>
#include "VulkanEngine.h"

int main() {
    try{
        VulkanEngine app;
        app.run();
    }
    catch(const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS; // 0
}
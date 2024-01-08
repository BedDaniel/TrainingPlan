#include "../Includes/Menu.hpp"
#include <filesystem>
#include <iostream>

int main(){
    // std::cout << "Current path: " << std::filesystem::current_path() << std::endl;
    Menu menu;
    menu.runMenu();
    
    return 0;
}
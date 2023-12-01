#include "../Includes/Menu.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>

void Menu::printMenu(){

}

void Menu::Menu_Add(){
    std::string name_;
    size_t sets_; size_t reps_; 
    float weight_;
    size_t choice = 1;
    char c;
    system("cls");
    std::cout << "\nName of the exercises: ";
    std::getline(std::cin, name_);
    system("cls");
    std::cout << "\nNumber of sets: ";
    std::cin >> sets_;
    system("cls");
    std::cout << "\nNumber of reps: ";
    std::cin >> reps_;
    system("cls");
    std::cout << "\nWeight: ";
    std::cin >> weight_;
    system("cls");

}
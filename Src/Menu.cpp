#include "../Includes/Menu.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>

void Menu::printMenu(){
    system("cls");

    std::cout << ". Add exercise to the plan";
                 ". Create a new training plan";
                 ". Show the whole training plan";
                 ". Show selected training day";
                 ". Delete exercises from plan";
                 ". Edit exercises from plan"; // name, reps, sets or laod
                 ". Add new training day";
                 ". Extract training plan to excel file";
                 ". ";
}

    void Menu::validateUserInput(size_t & choice){
    while(!(std::cin>>choice))
    {
        std::cout << "Please enter numbers only!\n";
        std::cin.clear();
        std::cin.ignore(100, '\n');
    }
}

void Menu::Menu_Add(){

    std::string name_;
    size_t sets_; size_t reps_; 
    float weight_;

    size_t choice = 1;
    char c;

    std::cout << "1. Add exercise \n"
                 "0. EXIT \n";

    while(choice != 0)
    {
        std::cout << "\nInsert number 1 or 0\n";
        validateUserInput(choice);
        std::cin.ignore();

        switch(choice)
        {
        case 1:
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
            plan.addExercise(name_, sets_, reps_, weight_);
            choice = 0;
            break;
        case 2:
            std::cout << '\n' << "BYE BYE BYE" << std::endl;
            break;
        }

    }
}

void Menu::runMenu(){
    //size_t choice;

}
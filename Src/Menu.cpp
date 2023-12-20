#include "../Includes/Menu.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>


    void Menu::validateUserInput(size_t & choice){
    while(!(std::cin>>choice))
    {
        std::cout << "Please enter numbers only!\n";
        std::cin.clear();
        std::cin.ignore(100, '\n');
    }
}


// void Menu::Menu_AddExerciseToTrainingDay(){

//     std::string name_;
//     size_t sets_; size_t reps_; 
//     float weight_;

//     size_t choice = 1;
//     char c;

//     std::cout << "1. Add exercise \n"
//                  "0. EXIT \n";

//     while(choice != 0)
//     {
//         std::cout << "\nInsert number 1 or 0\n";
//         Menu::validateUserInput(choice);
//         std::cin.ignore();

//         switch(choice)
//         {
//         case 1:
//             system("cls");
//             std::cout << "\nName of the exercises: ";
//             std::getline(std::cin, name_);
//             system("cls");
//             std::cout << "\nNumber of sets: ";
//             std::cin >> sets_;
//             system("cls");
//             std::cout << "\nNumber of reps: ";
//             std::cin >> reps_;
//             system("cls");
//             std::cout << "\nWeight: ";
//             std::cin >> weight_;
//             system("cls");
//             plan.addExercise(name_, sets_, reps_, weight_);
//             choice = 0;
//             break;
//         case 2:
//             std::cout << '\n' << "BYE BYE BYE" << std::endl;
//             break;
//         }

//     }
// }


void Menu::printMenu(){
    system("clear");
    std::cout << "1. Show training plan\n"
                 "2. Save training plan to a file\n"
                 "3. Load training plan from a file\n"
                 "4. Add exercise to training day\n"
                 "5. Add training day to plan\n"
                 "6. Remove exercise from training day\n"
                 "7. Remove training day from plan\n"
                 "8. Edit exercise in training day\n"
                 "9. Edit training day in plan\n"
                 "0. EXIT\n";
}

void Menu::runMenu(){
    size_t choice;
    // plan.loadSavedTrainingPlan(); 
    do
    {
        system("cls");
        std::cout << "1. Create new training plan\n";
        std::cout << "2. Load training plan\n";
        std::cout << "0. EXIT\n";
        std::cout << "\nInsert a number between 0 - 2\n>";
        validateUserInput(choice);

        switch (choice)
        {
        case 1:
            system("cls");
            std::cout << "You have just created new trainig plan!\n";
            system("PAUSE");
            break;
        case 2:
            Menu_LoadFromFile();
            break;
        case 0:
            system("cls");
            std::cout << "EXIT!\n";
            system("PAUSE");
            break;
        default:
            system("cls");
            std::cout << "You entered a wrong number!\n";
            system("PAUSE");
            break;
        }
    } while (choice < 0 or choice > 2);

    choice = 1;

    while(choice != 0)
    {
        system("clear");
        printMenu();
        std::cout << "\nInsert a number between 0 - Options!\n>";
        validateUserInput(choice);
        system("clear");

        switch (choice)
        {
        case 0:
            system("clear");
            std::cout << "EXIT!\n";
            std::cin.get();
            break;
        case 1:
            Menu_ShowTrainingPlan();
            break;
        case 2:
            Menu_SaveToFile();
            break;
        case 3:
            Menu_LoadFromFile();
            break;
        case 4:
            Menu_AddExerciseToTrainingDay();
            break;
        case 5:
            Menu_AddTrainingday();
            break;
        case 6:
            Menu_RemoveExerciseFromTrainingDay();
            break;
        case 7:
            Menu_RemoveTrainingDay();
            break;
        case 8:
            Menu_EditExerciseInTrainingDay();
            break;
        case 9:
            Menu_EditTrainingDay();
            break;
        default:
            system("clear");
            std::cout << "You entered a wrong char!\n";
            std::cin.get();
            break;
        }
    }
}
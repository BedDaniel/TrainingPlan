#include "../Includes/Menu.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <limits>


void Menu::validateUserInput(size_t & choice){
    while(!(std::cin>>choice))
    {
        std::cout << "\nPlease enter numbers only!\n";
        std::cin.clear();
        std::cin.ignore(100, '\n');
    }
}

void Menu::clearScreen() { std::cout << "\x1B[2J\x1B[H"; }

void Menu::Menu_ShowTrainingPlan(){
    char answer;
    if(plan.getTrainingDays().empty()) 
    {
        while (true) 
        {
            clearScreen();
            std::cout << "Plan is empty! You have to add new training day first!\n\n";
            std::cout << "Do you want to do this now ([Y] - yes | [N] - no, return to menu)? "; std::cin >> answer;

            switch(answer)
            {
            case 'Y':
            case 'y': 
                Menu_AddTrainingday(); 
                break;
            case 'N':
            case 'n': 
                return;
            default:
                clearScreen();;
                std::cout << "You entered wrong char!\n"; 
                std::cout << "\nPress enter to try again!\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.get();
                break;
            }
        }
    }

    else
    {   
        clearScreen();
        plan.displayTrainingDaysWithExercises();

        std::cout << "\nPress enter to back to menu...\n";
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }   
} 

void Menu::Menu_AddTrainingday(){
    clearScreen();
    char answer;
    std::string name;

    if (std::cin.peek() == '\n') { std::cin.ignore(); }

    while (true)
    {
        std::cout << "What is the name of your new training day?\n";
        std::cout << "Enter the name: ";
        std::getline(std::cin, name);

        if (!name.empty()) { break; } 
        
        else { std::cout << "\nName cannot be empty. Please enter a valid name.\n\n"; }
    }

    plan.makeWorkoutDay(name);

    while (true) 
    {   
        clearScreen();
        std::cout << "You have just created \"" << name << "\" training day!\n";
        std::cout << "\nDo you want to add some exercises? ([Y] - yes | [N] - no, return to menu)? "; std::cin >> answer;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            switch(answer)
            {
            case 'Y':
            case 'y': 
                Menu_AddExerciseToTrainingDay(); 
                break;
            case 'N':
            case 'n': 
                runMenu();
                break;
            default:
                clearScreen();
                std::cout << "You entered wrong char!\n"; 
                std::cout << "\nPress enter to try again!\n";
                // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.get();
                break;
            }
    }
}

void Menu::Menu_AddExerciseToTrainingDay(){
    if(plan.getTrainingDays().empty()) 
    {
        while (true)
        {
            char answer;
            clearScreen();
            std::cout << "There is no any training day!\n"
             "Do you want to create a new one ([Y] - yes | [N] - no)? "; std::cin >> answer;
            switch(answer)
            {
                case 'Y':
                case 'y': 
                    Menu_AddTrainingday(); 
                    break;

                case 'N':
                case 'n': 
                    return; 

                default: std::cout << "\nYou entered wrong answer (write y or n)!\n"; break;
            }
        }
    }
    else
    {   
        clearScreen();
        size_t choice;
        std::string name;
        int sets = 0; int reps = 0;
        float weight = 0.0f;

        plan.displayTrainingDays();
        std::cout << "\nSelect training day to which you want to add exercise: ";

        while (true) 
        {
            std::cin >> choice;
            
            if (std::cin.fail()) 
            {
                std::cout << "Invalid input. Please enter a number.\n";
                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            if(choice >= 1 and choice <= plan.getTrainingDays().size())
            {
                break;
            }

            else
            {
                std::cout << "Enter the number between 1 and " << plan.getTrainingDays().size() << '\n';
            }
        }
            clearScreen();
            std::cout << "You are adding exercise to: " << plan.getTrainingDays()[choice-1]->getWorkoutDayName() << '\n';

            if (std::cin.peek() == '\n') { std::cin.ignore(); }

            while(true)
            {
                std::cout << "\nExercise's name: "; 
                std::getline(std::cin, name);

                if (!name.empty()) { break; } 

                else { std::cout << "\nName cannot be empty. Please enter a name again.\n\n"; }
            }

            while (true) {
                std::cout << "Number of sets: "; std::cin >> sets;
                if (std::cin.fail() || sets <= 0) 
                {
                    std::cout << "\nWrong input! Try again!\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                break;
            }
            while (true) {
                std::cout << "Number of reps: "; std::cin >> reps;
                if (std::cin.fail() || reps <= 0) 
                {
                    std::cout << "Wrong input! Try again!\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                break;
            }

            while (true) 
            {
                std::cout << "Amount of load (you can use decimal numbers): "; std::cin >> weight;
                if (std::cin.fail() || weight < 0) {
                    std::cout << "Wrong input! Try again\n";
                    std::cin.clear(); 
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                break;
            }

            plan.getTrainingDays()[choice-1]->addExercise(name, sets, reps, weight);

            bool contiuneAdding = true;
            while (contiuneAdding)
            {
                clearScreen();
                std::cout << "You have just added " << name << " to "<< plan.getTrainingDays()[choice-1]->getWorkoutDayName() << '\n';
                char answer;
                std::cout << "\nDo you want another exercise? ([Y] - yes | [N] - no, return to menu)? "; std::cin >> answer;
                    switch(answer)
                {
                        case 'Y':
                        case 'y': Menu_AddExerciseToTrainingDay(); break;

                        case 'N':
                        case 'n': 
                            contiuneAdding = false;
                            break; 

                        default: 
                            clearScreen();
                            std::cout << "You entered wrong char!\n"; 
                            std::cout << "\nPress enter to try again!\n";
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            // std::cin.get();std::cout << "\nYou entered wrong answer (write y or n)!\n"; 
                            break;
                }
            }

    }
}

void Menu::printMenu(){
    clearScreen();
    std::cout << "1. Show training plan\n"
                 "2. Save training plan to a file\n"
                 "3. Load training plan from a file\n"
                 "4. Add exercise to training day\n"
                 "5. Add training day to plan\n"
                 "6. Remove exercise from training day\n"
                 "7. Remove training day from plan\n"
                 "8. Edit exercise in training day\n"
                 "9. Edit training day in plan\n\n"
                 "0. EXIT\n";
}

void Menu::runMenu(){
    size_t choice;

    if (std::cin.peek() == '\n') { std::cin.ignore(); 
    // plan.loadSavedTrainingPlan(); 
    do
    {
        clearScreen();
        std::cout << "1. Create new training plan\n";
        std::cout << "2. Load training plan\n\n";
        std::cout << "0. EXIT\n\n";
        std::cout << "Insert a number between 0 - 2: ";
        validateUserInput(choice);

        switch (choice)
        {
        case 1:
            clearScreen();
            std::cout << "You have just created new trainig plan!\n";
            system("PAUSE");
            break;
        case 2:
            Menu_LoadFromFile();
            break;
        case 0:
            clearScreen();
            std::cout << "\nPRESS ENTER TO EXIT\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();
            break;
        default:
            clearScreen();
            std::cout << "You entered a wrong number!\n";
            std::cout << "Press enter to try again!\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();
            break;
        }
    } while (choice < 0 or choice > 2);

    choice = 1;

    while(choice != 0)
    {
        clearScreen();
        printMenu();

        if (std::cin.peek() == '\n') { std::cin.ignore(); }

        std::cout << "\nInsert a number between 0 - 9: ";
        validateUserInput(choice);
        clearScreen();

        switch (choice)
        {
        case 0:
            clearScreen();
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
            clearScreen();
            std::cout << "You entered a wrong char!\n";
            std::cout << "Press enter to try again!\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();
            break;
        }
    }
}
}
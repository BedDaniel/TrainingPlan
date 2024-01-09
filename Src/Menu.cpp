#include "../Includes/Menu.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <limits>
#include <filesystem>
#include <cstdlib>


void Menu::clearScreen() { std::cout << "\x1B[2J\x1B[H"; }

void Menu::runMenu(){
    size_t choice;
    
    do
    {
        clearScreen();
        std::cout << "1. Create new training plan\n";
        std::cout << "2. Load training plan\n\n";
        std::cout << "0. EXIT\n\n";
        std::cout << "Insert a number between 0 - 2: ";

        switch (choice)
        {
        case 1:
            runMainMenu();
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
    } while (choice != 0);
}

void Menu::printMainMenu(){
    clearScreen();
    std::cout << "1. Show training plan\n"
                 "2. Save training plan to a file\n"
                 "3. Load training plan from a file\n"
                 "4. Add exercise to training day\n"
                 "5. Add training day to plan\n"
                 "6. Remove exercise from training day\n"
                 "7. Remove training day from plan\n"
                 "8. Swap exercises in training day\n"
                 "9. Edit training day in plan\n\n"
                 "0. EXIT\n";
}

void Menu::runMainMenu(){
    size_t choice = 0;

    do
    {
        clearScreen();
        printMainMenu();

        std::cout << "\nInsert a number between 0 - 9: ";

        while (true) {
            if (std::cin.peek() == '\n') { std::cin.ignore(); }

            if (std::cin >> choice && choice >= 0 && choice <= 9) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                break;
            } else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                clearScreen();
                printMainMenu();
                std::cout << "Invalid input. Please enter a number between 0 - 9: ";
            }
        }
        clearScreen();

        switch (choice)
        {
        case 0:
            clearScreen();
            Menu_exitProgram();
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
            Menu_SwapExercisesInTrainingDay();
            break;
        case 9:
            Menu_EditExerciseInTrainingDay();
            break;
        default:
            clearScreen();
            std::cout << "You entered a wrong char!\n";
            std::cout << "Press enter to try again!\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();
            break;
        }
    } while(choice != 0);
}



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

void Menu::Menu_SaveToFile() {
    clearScreen();
    if (plan.getTrainingDays().empty()) 
    {
        std::cout << "Training plan is empty. There is nothing to save.\n\n";
        std::cout << "Press enter to return to the menu.";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        return;
    }

    std::string filename;
    std::string directory = "Saved_Training_Plans";

    std::filesystem::path dirPath = std::filesystem::current_path() / directory;
    if (!std::filesystem::exists(dirPath)) 
    {
        std::filesystem::create_directory(dirPath);
    }

    while (true) 
    {
        std::cout << "Enter the filename to save the training plan: "; /* (without '.txt' extension): "; */
        std::getline(std::cin, filename);
        std::filesystem::path filePath = dirPath / (filename + ".txt");

        std::ifstream fileCheck(filename);

        if (std::filesystem::exists(filePath)) 
        {
            clearScreen();
            std::cout << "A file named: \n'" << filePath << "' already exists. Please choose a different name.\n";
        } 
        else 
        {
            plan.saveToFile(filePath.string());
            plan.addSavedFileNames(filePath.string());
            break;
        }
    }

    plan.saveToFile(filename);
    plan.addSavedFileNames(filename);

    clearScreen();
    std::cout << "Training plan saved to '" << filename << ".txt' successfully.\n\n";
    std::cout << "Press enter to return to the menu.";
    std::cin.get();
}

void Menu::Menu_LoadFromFile() {
    clearScreen();
    std::string directory = "Saved_Training_Plans";
    std::filesystem::path dirPath = std::filesystem::current_path() / directory;

    if (!std::filesystem::exists(dirPath) || std::filesystem::is_empty(dirPath)) 
    {
        if (!std::filesystem::exists(dirPath)) 
        {
            std::filesystem::create_directory(dirPath);
        }
        std::cout << "Currently, there are no saved training plans.\n";
        std::cout << "Do you want to create a new plan now? (Y/N): ";

        char choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 'Y' || choice == 'y') 
        {
            Menu_AddTrainingday();
        } 
        else { return; }
    } 
    
    else 
    {
        std::cout << "Available training plans:\n";
        int fileIndex = 1;
        std::vector<std::string> fileNames;

        for (const auto& entry : std::filesystem::directory_iterator(dirPath)) 
        {
            if (entry.is_regular_file()) 
            {
                std::cout << fileIndex << ". " << entry.path().filename() << std::endl;
                fileNames.push_back(entry.path().filename());
                fileIndex++;
            }
        }

        std::cout << "\nEnter the number of the plan you want to load: ";
        int choice;
        std::cin >> choice;

        if (choice < 1 || choice > fileNames.size()) 
        {
            std::cout << "Invalid choice. Press enter to return to the menu.";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();
            return;
        }

        std::string selectedFile = fileNames[choice - 1];
        std::filesystem::path filePath = dirPath / selectedFile;
        
        plan.clearTrainingDays();
        plan.loadFromFile(filePath.string());

        clearScreen();
        std::cout << "Training plan '" << selectedFile << "' loaded successfully.\n";
        std::cout << "Press enter to return to the menu.";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        runMainMenu();
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

                default: std::cout << "\n\nYou entered wrong answer (write y or n)!\n"; break;
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
                std::cout << "\nInvalid input. Please enter a number.\n";
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

            while (true) 
            {
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

            while (true) 
            {
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
                if (std::cin.fail() || weight < 0) 
                {
                    std::cout << "Wrong input! Try again\n";
                    std::cin.clear(); 
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                break;
            }

            plan.getTrainingDays()[choice-1]->addExercise(name, sets, reps, weight);

            while (true)
            {
                clearScreen();
                std::cout << "You have just added " << name << " to "<< plan.getTrainingDays()[choice-1]->getWorkoutDayName() << '\n';
                char answer;
                std::cout << "\nDo you want another exercise? ([Y] - yes | [N] - no, return to menu)? "; std::cin >> answer;
                switch(answer)
                {
                    case 'Y':
                    case 'y': 
                        Menu_AddExerciseToTrainingDay(); 
                        break;

                    case 'N':
                    case 'n': 
                        runMainMenu();
                        break; 

                    default: 
                        clearScreen();
                        std::cout << "You entered wrong char!\n"; 
                        std::cout << "\nPress enter to try again!\n";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        break;
                }
            }
    }
}

void Menu::Menu_AddTrainingday(){
    char answer;
    std::string name;
    clearScreen();

    while (true)
    {
        std::cout << "What is the name of your new training day?\n\n";
        std::cout << "Enter the name: ";
        if (std::cin.peek() == '\n') { std::cin.ignore(); }
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
                runMainMenu();
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

void Menu::Menu_RemoveExerciseFromTrainingDay(){
    clearScreen();
    char answer;
    if(plan.getTrainingDays().empty())
    {   
        while(true)
        {
        clearScreen();
        std::cout << "There is no any training day in your training plan!\n";  
        std::cout << "Do you want to add a new training day? ([Y] - yes | [N] - no, return to menu)? "; std::cin >> answer;
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
        size_t dayChoice = 0;
        size_t exerciseChoice = 0;
        while(true)
        {
            clearScreen();
            std::cout << "Select the training day you want to delete from\n\n";
            plan.displayTrainingDays();
            std::cout << "\nNumber of selected training day: ";

            if(std::cin >> dayChoice && dayChoice >= 1 && dayChoice <= plan.getTrainingDays().size())
            { 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break; 
            }

            else
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                clearScreen();
                std::cout << "Invalid input. Press enter to try agian!";
                std::cin.get();
            }
        }

        auto selectedDay = plan.getTrainingDays()[dayChoice - 1];

        if (selectedDay->getExercises().empty()) 
        {
            clearScreen();
            std::cout << "There are no exercises in this training day.\n\n";
            std::cout << "Press enter to return to the menu.";
            std::cin.get();
            return;
        } 
        else 
        {
            while (true) 
            {
                clearScreen();
                std::cout << "Select the exercise you want to remove:\n\n";
                selectedDay->displayTrainingDay();
                std::cout << "\nNumber of selected exercise: ";

                if (std::cin >> exerciseChoice && exerciseChoice >= 1 && exerciseChoice <= selectedDay->getExercises().size()) 
                {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                } 

                else 
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    clearScreen();
                    std::cout << "Invalid input. Press enter to try again!";
                    std::cin.get();
                }
            }

            selectedDay->removeExercise(exerciseChoice - 1);
            clearScreen();
            std::cout << "Exercise removed successfully.\n\n";
            std::cout << "Press enter to return to the menu.";
            std::cin.get();
        }
    }
}

void Menu::Menu_RemoveTrainingDay(){
    clearScreen();
    if (plan.getTrainingDays().empty()) {
        std::cout << "There are no training days in your training plan!\n";  
        std::cout << "Press enter to return to the menu.";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        return;
    } 

    size_t dayChoice = 0;

    while (true) 
    {
        clearScreen();
        std::cout << "Select the training day you want to remove:\n\n";
        plan.displayTrainingDays();
        std::cout << "\nNumber of selected training day: ";
        
        if (std::cin >> dayChoice && dayChoice >= 1 && dayChoice <= plan.getTrainingDays().size()) 
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        } 
        else 
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Press enter to try again!";
            std::cin.get();
        }
    }

    plan.removeTrainingDay(dayChoice - 1);
    clearScreen();
    std::cout << "Training day removed successfully.\n\n";
    std::cout << "Press enter to return to the menu.";
    std::cin.get();
}

void Menu::Menu_SwapExercisesInTrainingDay() {
    clearScreen();
    if (plan.getTrainingDays().empty()) 
    {
        std::cout << "There are no training days in your plan!\n\n";
        std::cout << "Press enter to return to the menu.";
        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        return;
    }

    size_t dayChoice = 0, firstExerciseChoice = 0, secondExerciseChoice = 0;

    while (true) 
    {
        clearScreen();
        std::cout << "Select the training day:\n\n";
        plan.displayTrainingDays();
        std::cout << "\nNumber of selected training day: ";

        if (std::cin >> dayChoice && dayChoice >= 1 && dayChoice <= plan.getTrainingDays().size()) 
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        } 
        else 
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Press enter to try again!";
            std::cin.get();
        }
    }

    auto selectedDay = plan.getTrainingDays()[dayChoice - 1];

    if (selectedDay->getExercises().size() < 2) 
    {
        clearScreen();
        std::cout << "Not enough exercises to swap in the selected day.\n";
        std::cout << "Press enter to return to the menu.";
        std::cin.get();
        return;
    } 
    else 
    {
        while (true) 
        {
            clearScreen();
            std::cout << "Select two exercises to swap:\n\n";
            selectedDay->displayTrainingDay();
            std::cout << "\nNumber of the first exercise: ";
            if (std::cin >> firstExerciseChoice && firstExerciseChoice >= 1 && firstExerciseChoice <= selectedDay->getExercises().size()) 
            {
                std::cout << "Number of the second exercise: ";

                if (std::cin >> secondExerciseChoice && secondExerciseChoice >= 1 && secondExerciseChoice <= selectedDay->getExercises().size() && firstExerciseChoice != secondExerciseChoice) 
                {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input or same exercises selected. Press enter to try again!";
            std::cin.get();
        }

        selectedDay->swapExercises(firstExerciseChoice - 1, secondExerciseChoice - 1);
        clearScreen();
        std::cout << "Exercises swapped successfully.\n\n";
        std::cout << "This is how your training plan looks like now!\n\n";
        selectedDay->displayTrainingDay();

        std::cout << "\nPress enter to return to the menu.";
        std::cin.get();
    }
}

void Menu::Menu_EditExerciseInTrainingDay() {
    clearScreen();
    if (plan.getTrainingDays().empty()) {
        std::cout << "There are no training days in your plan!\n";
        std::cout << "Press enter to return to the menu.";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        return;
    }

    size_t dayChoice = 0;
    char menuChoice;

    while (true) {
        clearScreen();
        std::cout << "Select the training day you want to edit:\n\n";
        plan.displayTrainingDays();
        std::cout << "\nNumber of selected training day: ";
        if (std::cin >> dayChoice && dayChoice >= 1 && dayChoice <= plan.getTrainingDays().size()) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Press enter to try again!";
            std::cin.get();
        }
    }

    auto& selectedDay = plan.getTrainingDays()[dayChoice - 1];

    clearScreen();
    std::cout << "Selected day: " << selectedDay->getWorkoutDayName() << "\n\n";
    std::cout << "1. Change the name of the training day\n";
    std::cout << "2. Modify an exercise\n\n";
    std::cout << "0. Exit\n\n";
    std::cout << "Enter your choice: ";
    std::cin >> menuChoice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (menuChoice) 
    {
        case '1':
        {   
            clearScreen();
            std::string newDayName;
            std::cout << "Enter new name for the training day: ";
            std::getline(std::cin, newDayName);
            if (!newDayName.empty()) 
            {
                selectedDay->setWorkoutDayName(newDayName);
                std::cout << "\nTraining day name updated successfully.\n";
            } 
            else 
            {
                std::cout << "Name cannot be empty.\n";
            }
            break;
        }

        case '2':
        {
            size_t exerciseChoice = 0;
            if (selectedDay->getExercises().empty()) 
            {
                clearScreen();
                std::cout << "There are no exercises in this training day.\n";
                std::cout << "Press enter to return to the menu.";
                std::cin.get();
                return;
            } 
            else 
            {
                while (true) 
                {
                    clearScreen();
                    std::cout << "Select the exercise you want to edit:\n\n";
                    selectedDay->displayTrainingDay();
                    std::cout << "\nNumber of selected exercise: ";

                    if (std::cin >> exerciseChoice && exerciseChoice >= 1 && exerciseChoice <= selectedDay->getExercises().size()) 
                    {
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        break;
                    } 
                    else 
                    {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid input. Press enter to try again!";
                        std::cin.get();
                    }
                }

                auto& exerciseToEdit = selectedDay->getExercises()[exerciseChoice - 1];

                std::string newName;
                size_t newSets, newReps;
                float newWeight;

                clearScreen();
                std::cout << "Editing exercise: " << exerciseToEdit->getName() << "\n\n";

                std::cout << "Enter new name or press enter to skip: ";
                std::getline(std::cin, newName);
                if (!newName.empty()) 
                {
                    exerciseToEdit->setName(newName);
                }

                std::cout << "Enter new number of sets (current: " << exerciseToEdit->getSets() << ") or enter 0 to skip: ";
                if (std::cin >> newSets && newSets > 0) 
                {
                    exerciseToEdit->setSets(newSets);
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Enter new number of reps (current: " << exerciseToEdit->getReps() << ") or enter 0 to skip: ";
                if (std::cin >> newReps && newReps > 0) 
                {
                    exerciseToEdit->setReps(newReps);
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Enter new weight (current: " << exerciseToEdit->getWeight() << ") or enter 0 to skip: ";
                if (std::cin >> newWeight && newWeight >= 0) 
                {
                    exerciseToEdit->setWeight(newWeight);
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                clearScreen();
                std::cout << "Exercise updated successfully!\n\n";
                std::cout << "That is how it looks like now!\n\n";
                std::cout << "Exercise name: ";
                exerciseToEdit->displayExerciseInfo();

                std::cout << "\nPress enter to return to the menu.";
                std::cin.get();
            break;
            }
        }
        case '0':
        {
            return;
        }
        default:
        {
            std::cout << "Invalid choice. Press enter to try again.";
            std::cin.get();
            break;
        }
    }

    // std::cout << "\nPress enter to return to the menu.";
    // std::cin.get();
}

void Menu::Menu_exitProgram(){
    char choice;
    std::cout << "Do you want to save your training plan before exiting? (Y/N): ";
    std::cin >> choice;

    if (choice == 'Y' or choice == 'y') { Menu_SaveToFile(); }

    std::cout << "\nExiting the program. Have a nice day!\n";
    exit(0);
}
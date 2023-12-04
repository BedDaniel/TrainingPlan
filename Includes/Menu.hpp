#include "../Includes/TrainingPlan.hpp"

class Menu{
public:
    Menu() {}
    void runMenu();

private:
    TrainingPlan plan;
    void printMenu();
    void Menu_Add();
    

    void Menu_SaveToFile();
    void Menu_LoadFromFile();

    void Menu_LoadSavedFile();
    void showSavedFiles();

    void validateUserInput(size_t & choice);


};
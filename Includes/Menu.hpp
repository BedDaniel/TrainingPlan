#include "../Includes/TrainingPlan.hpp"
#include "../Includes/Exercises.hpp"

class Menu{
public:
    Menu() {}
    void runMenu();
    static void validateUserInput(size_t & choice);

private:
    TrainingPlan plan;
    void printMenu();
    void Menu_Add();
    

    void Menu_SaveToFile();
    void Menu_LoadFromFile();

    void Menu_LoadSavedFile();
    void showSavedFiles();



};
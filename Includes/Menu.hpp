#pragma once
#include "../Includes/TrainingPlan.hpp"

class Menu{
public:
    Menu() {};
    void runMenu();
    void runMainMenu();

private:
    TrainingPlan plan;
    void printMainMenu();
    void clearScreen();

    void Menu_ShowTrainingPlan();

    void Menu_Add();
    void Menu_AddExerciseToTrainingDay();
    void Menu_AddTrainingday();

    void Menu_Remove();
    void Menu_RemoveExerciseFromTrainingDay();
    void Menu_RemoveTrainingDay();

    void Menu_Edit();
    void Menu_SwapExercisesInTrainingDay();
    void Menu_EditExerciseInTrainingDay();

    void Menu_SaveToFile();
    void Menu_LoadFromFile();

    void Menu_exitProgram();

};
#pragma once
#include "../Includes/TrainingPlan.hpp"

class Menu{
public:
    Menu() {};
    void runMenu();
    static void validateUserInput(size_t & choice);

private:
    TrainingPlan plan;
    void printMenu();
    void Menu_AddExerciseToTrainingDay();

    void Menu_RemoveExerciseFromTrainingDay();
    void Menu_RemoveTrainingDay();

    void Menu_SwapExercisesInTrainingDay();
    void Menu_EditExercise();

    void Menu_SaveToFile();
    void Menu_LoadFromFile();

};
#include "../Includes/TrainingPlan.hpp"
#include <iostream>

TrainingPlan::TrainingPlan(){}

void TrainingPlan::addExercise(const Exercise & exercise){
    exercises_.push_back(exercise);
}

void TrainingPlan::displayPlan() const {
    std::cout << "\nTraining plan: \n";
    for(const auto & ex : exercises_)
    {
        ex.displayExerciseInfo();
    }
}
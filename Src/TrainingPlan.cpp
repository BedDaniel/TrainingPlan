#include "../Includes/TrainingPlan.hpp"
#include <iostream>


TrainingPlan::TrainingPlan(){}

void TrainingPlan::addExercise(const std::string & name, size_t sets, size_t reps, float weight){
    exercises_.push_back(std::make_shared<Exercise>(name, sets, reps, weight));
}

void TrainingPlan::displayPlan() const {
    std::cout << "\nTraining plan: \n";
    for(const auto & ex : exercises_)
    {
        ex->displayExerciseInfo();
    }
}
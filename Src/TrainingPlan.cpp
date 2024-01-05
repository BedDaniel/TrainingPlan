#include "../Includes/TrainingPlan.hpp"
#include "../Includes/Menu.hpp"
#include "../Includes/TrainingDay.hpp"
#include <iostream>
#include <limits>
 

void TrainingPlan::makeWorkoutDay(const std::string& name) {
    std::vector<std::shared_ptr<Exercise>> emptyExercises;
    trainingDays_.push_back(std::make_shared<TrainingDay>(name, emptyExercises));
}

void TrainingPlan::displayTrainingDays() const {
    int num = 1;
    for (const auto& trainingDay : trainingDays_) {
        std::cout << num << ". " << trainingDay->getWorkoutDayName() << '\n';
        ++num;
    }
}

void TrainingPlan::displayTrainingDaysWithExercises() const {
    for (const auto& trainingDay : trainingDays_) 
    {
        trainingDay->displayTrainingDay(); 
    }
}


void TrainingPlan::removeTrainingDay(int pos) {
    auto iteratorToRemove = trainingDays_.begin() + pos - 1;
    trainingDays_.erase(iteratorToRemove);
}




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
    int num = 1;
    for (const auto& trainingDay : trainingDays_) 
    {   
        std::cout << num << ". ";
        trainingDay->displayTrainingDay();
        ++num;
    }
}

void TrainingPlan::removeTrainingDay(int pos) {
    auto iteratorToRemove = trainingDays_.begin() + pos;
    trainingDays_.erase(iteratorToRemove);
}

void TrainingPlan::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) 
    {
        std::cerr << "Could not open file " << filename << " for writing.\n";
        return;
    }

    for (const auto& day : trainingDays_) 
    {
        outFile << "Day: " << day->getWorkoutDayName() << "\n";

        for (const auto& exercise : day->getExercises()) 
        {
            outFile << "Exercise: " << exercise->getName() << ", ";
            outFile << "Sets: " << exercise->getSets() << ", ";
            outFile << "Reps: " << exercise->getReps() << ", ";
            outFile << "Weight: " << exercise->getWeight() << "\n";
        }
        outFile << "---\n";
    }

    // std::cout << "Training plan saved to " << filename << std::endl;
}




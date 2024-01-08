#include "../Includes/TrainingDay.hpp"
#include <iostream>

void TrainingDay::displayTrainingDay() const {
    int num = 1;
    std::cout << "training day: " << workoutDayName_ << "\n";
    
    if (exercises_.empty()) 
    {
        std::cout << "\nThere is no any exercise in this day.\n";
    } 
    else 
    {   
        int num = 1;
        std::cout << "\nExercises:\n";
        for (const auto& exercise : exercises_) {
            // std::cout << num << ". " << exercise->getName() << '\n';
            std::cout << num << ". ";
            exercise->displayExerciseInfo();
            ++num;
        }
    }
    std::cout << "\n------------------------------------------------\n";
}

void TrainingDay::removeExercise(int choice){
        auto iteratorToRemove = exercises_.begin() + choice;
        exercises_.erase(iteratorToRemove);
}

void TrainingDay::swapExercises(int oldPosition, int newPosition) {
    if (oldPosition >= 0 && oldPosition < exercises_.size() &&
        newPosition >= 0 && newPosition < exercises_.size()) {
        std::iter_swap(exercises_.begin() + oldPosition, exercises_.begin() + newPosition);
    } else {
        std::cout << "Invalid positions provided for swapping.\n";
    }
}

void TrainingDay::addExercise(const std::string & name, size_t sets, size_t reps, float weight){
    exercises_.push_back(std::make_shared<Exercise>(name, sets, reps, weight));
}
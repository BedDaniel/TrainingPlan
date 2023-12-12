#include "../Includes/TrainingDay.hpp"
#include <iostream>

void TrainingDay::display() const {
    std::cout << "Workout Day: " << workoutDayName_ << "\n";
    
    if (exercises_.empty()) {
        std::cout << "No exercises for this day.\n";
    } else {
        std::cout << "Exercises:\n";
        for (const auto& exercise : exercises_) {
            std::cout << "  - " << exercise->getName() << " (Sets: " << exercise->getSets()
                      << ", Reps: " << exercise->getReps() << ", Weight: " << exercise->getWeight() << ")\n";
        }
    }
    std::cout << "\n";
}


void TrainingDay::removeExercise(int choice){
        auto iteratorToRemove = exercises_.begin() + choice - 1;
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
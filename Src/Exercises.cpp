#include "../Includes/Exercises.hpp"

#include <iostream>

Exercise::Exercise() {}

Exercise::Exercise(std::string name, size_t sets, size_t reps, float weight) 
                : name_(name), sets_(sets), reps_(reps), weight_(weight) {}
    
void Exercise::displayExerciseInfo() const {
    // std::cout << name_ << "\tSets: " << sets_ << "\tReps: " << reps_ << "\tLoad: " << weight_ << '\n';
    std::cout << std::setw(25) << std::left << name_
              << " " << std::setw(6) << sets_
              << " " <<std::setw(6) << reps_
              << "  " <<std::setw(8) << weight_
              << "\n";
              
}

void Exercise::displayExerciseInfoInEditFunction() const {
    std::cout << name_ << "\nSets: " << sets_ << "\nReps: " << reps_ << "\nLoad: " << weight_ << '\n';
}
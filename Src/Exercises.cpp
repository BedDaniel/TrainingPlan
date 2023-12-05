#include "../Includes/Exercises.hpp"



#include <iostream>

Exercise::Exercise() {}

Exercise::Exercise(std::string name, size_t sets, size_t reps, float weight) 
                : name_(name), sets_(sets), reps_(reps), weight_(weight) {}
                
void Exercise::displayExerciseInfo() const {
    std::cout << name_ << "\tSets: " << sets_ << "\tReps: " << reps_ << "\tLoad: " << weight_ << '\n';
}

#include "../Includes/Exercises.hpp"
#include <iostream>

Exercise::Exercise() {}

Exercise::Exercise(std::string name, size_t sets, size_t reps, float weight) 
                : name_(name), sets_(sets), reps_(reps), weight_(weight) {}
                
void Exercise::displayExerciseInfo() const {
    std::cout << "\nName of exercise: " << name_ << "\nNumber of sets: " << sets_ << "\nNumber of reps: " << reps_ << "\nWeight in each set: " << weight_ << '\n';
}

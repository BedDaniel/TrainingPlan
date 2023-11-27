#pragma once
#include <vector>
#include "../Includes/Exercises.hpp"

class TrainingPlan{
public:
    TrainingPlan();
    void addExercise(const Exercise & exercise);

    void displayPlan() const;

private:
    std::vector<Exercise> exercises_;

};


#pragma once
#include <vector>
#include <memory>
#include <string>
#include "../Includes/Exercises.hpp"

class TrainingPlan{
public:
    TrainingPlan();
    void addExercise(const std::string & name, size_t sets, size_t reps, float weight);

    void displayPlan() const;

private:
    std::vector<std::shared_ptr<Exercise>> exercises_;

};


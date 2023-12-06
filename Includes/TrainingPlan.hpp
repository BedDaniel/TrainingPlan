#pragma once
#include <vector>
#include <memory>
#include <string>
#include "../Includes/Exercises.hpp"
//#include "../Includes/Menu.hpp"

class TrainingPlan{
public:
    TrainingPlan();
    void addExercise(const std::string & name, size_t sets, size_t reps, float weight);

    void displayPlan() const;
    std::vector<std::string> getFIleNames() const { return fileName_; };
    void editExercise();

    std::vector<std::shared_ptr<Exercise>> getExercise() const { return exercises_; } // Only for tests!

private:
    std::vector<std::shared_ptr<Exercise>>exercises_;

    std::vector<std::string> fileName_;

};


#pragma once
#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include "../Includes/Exercises.hpp"
#include "../Includes/TrainingDay.hpp"

//#include "../Includes/Menu.hpp"

class TrainingPlan{
public:
    std::shared_ptr<TrainingDay> makeWorkoutDay(const std::string& name, const std::vector<std::shared_ptr<Exercise>>& exercises);
    void displayTrainingDays() const;

    TrainingPlan();
    // Zrobione
    void displayPlan() const;

    void editExercise();
    // Do zrobienia:

    std::vector<std::string> getFIleNames() const { return fileName_; };


    //std::vector<std::shared_ptr<Exercise>> getExercise() const { return exercises_; } // Only for tests!

private:

    std::vector<std::shared_ptr<TrainingDay>> trainingDays_;

    std::vector<std::string> fileName_;

};


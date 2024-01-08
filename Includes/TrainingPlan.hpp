#pragma once
#include <vector>
#include <memory>
#include <fstream>
#include <string>
#include <algorithm>
#include "../Includes/Exercises.hpp"
#include "../Includes/TrainingDay.hpp"

//#include "../Includes/Menu.hpp"

class TrainingPlan{
public:
    TrainingPlan(){};
    TrainingPlan(const std::vector<std::shared_ptr<TrainingDay>> & trainingDays) : trainingDays_(trainingDays) {};

    std::shared_ptr<TrainingDay> makeWorkoutDay(const std::string& name, const std::vector<std::shared_ptr<Exercise>>& exercises);
    
    void makeWorkoutDay(const std::string& name);

    void displayTrainingDays() const;
    void displayTrainingDaysWithExercises() const;

    void removeTrainingDay(int pos);

    void clearTrainingDays();

    std::vector<std::string> getFIleNames() const { return fileName_; };
    std::vector<std::shared_ptr<TrainingDay>> & getTrainingDays () { return trainingDays_; }

    void saveToFile(const std::string& filename) const;

private:
    std::vector<std::shared_ptr<TrainingDay>> trainingDays_;

    std::vector<std::string> fileName_;
};


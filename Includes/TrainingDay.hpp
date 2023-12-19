#pragma once
#include "../Includes/Exercises.hpp"
#include <vector>
#include <memory>


class TrainingDay{
public:
    TrainingDay(const std::string& name, const std::vector<std::shared_ptr<Exercise>>& exercises)
            : workoutDayName_(name), exercises_(exercises) {}

    void displayTrainingDay() const;

    void removeExercise(int choice);

    void swapExercises(int oldPosition, int newPosition);

    void addExercise(const std::string & name, size_t sets, size_t reps, float weight);

    void setWorkoutDayName(std::string newDayName) { workoutDayName_ = newDayName; }

    std::string getWorkoutDayName()       const { return workoutDayName_;}
    std::vector<std::shared_ptr<Exercise>> getExercises() const { return exercises_;}

private:
    std::string workoutDayName_;
    std::vector<std::shared_ptr<Exercise>> exercises_;
};



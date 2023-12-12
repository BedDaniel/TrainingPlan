#pragma once
#include <string>

//#include "../Includes/TrainingPlan.hpp"
//#include "../Includes/Menu.hpp"

class Exercise{
public:
    Exercise();
    Exercise(std::string name, size_t sets, size_t reps_, float weight);

    // Setters
    void setName(std::string & newName)   { name_ = newName;}
    void setSets(size_t newSets)        { sets_ = newSets;}
    void setReps(size_t newReps)        { reps_ = newReps;}
    void setWeight(float newWeight)     { weight_ = newWeight;}

    // Getters
    std::string getName() const { return name_; }
    size_t getSets()      const { return sets_; }
    size_t getReps()      const { return reps_; }
    float getWeight()     const { return weight_;}

    void displayExerciseInfo() const;
    
private:
    std::string name_;
    size_t sets_;
    size_t reps_;
    float weight_;
};



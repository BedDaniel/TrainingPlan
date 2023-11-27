#pragma once
#include <string>

class Exercise{
public:
    Exercise();
    Exercise(std::string name, size_t sets, size_t reps_, float weight);

    // Setters
    void setName(std::string newName)   { name_ = newName;}
    void setSets(size_t newSets)        { sets_ = newSets;}
    void setReps(size_t newReps)        { reps_ = newReps;}
    void setWeight(float newWeight)     { weight_ = newWeight;}

    // Getters
    std::string getName()   { return name_; }
    size_t getSets()        { return sets_; }
    size_t getReps()        { return reps_; }
    float getWeight()       { return weight_;}

    void displayExerciseInfo() const;



private:
    std::string name_;
    size_t sets_;
    size_t reps_;
    float weight_;


};



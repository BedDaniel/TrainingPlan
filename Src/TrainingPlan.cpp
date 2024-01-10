#include "../Includes/TrainingPlan.hpp"
#include "../Includes/Menu.hpp"
#include "../Includes/TrainingDay.hpp"
#include <iostream>
#include <limits>
 

void TrainingPlan::makeWorkoutDay(const std::string& name) {
    std::vector<std::shared_ptr<Exercise>> emptyExercises;
    trainingDays_.push_back(std::make_shared<TrainingDay>(name, emptyExercises));
}

void TrainingPlan::displayTrainingDays() const {
    int num = 1;
    for (const auto& trainingDay : trainingDays_) {
        std::cout << num << ". " << trainingDay->getWorkoutDayName() << '\n';
        ++num;
    }
}

void TrainingPlan::displayTrainingDaysWithExercises() const {
    int num = 1;

    for (const auto& trainingDay : trainingDays_) 
    {   
        trainingDay->displayTrainingDay();
    }
}

void TrainingPlan::removeTrainingDay(int pos) {
    auto iteratorToRemove = trainingDays_.begin() + pos;
    trainingDays_.erase(iteratorToRemove);
}

void TrainingPlan::saveToFile(const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) 
    {
        std::cerr << "Could not open file " << filename << " for writing.\n";
        return;
    }
    
    for (const auto& day : trainingDays_) 
    {
        outFile << "Day: " << day->getWorkoutDayName() << "\n";

        for (const auto& exercise : day->getExercises()) 
        {
            outFile << "Exercise: " << exercise->getName() << ", ";
            outFile << "Sets: " << exercise->getSets() << ", ";
            outFile << "Reps: " << exercise->getReps() << ", ";
            outFile << "Weight: " << exercise->getWeight() << "\n";
        }
        outFile << "---\n";
    }
    currentFileName_ = filename;
}

void TrainingPlan::clearTrainingDays(){
    trainingDays_.clear();
}

void TrainingPlan::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) 
    {
        std::cerr << "Could not open file " << filename << " for reading.\n";
        return;
    }
    currentFileName_ = filename;
    std::string line;

    while (std::getline(inFile, line)) 
    {
        if (line.starts_with("Day: ")) 
        {
            std::string dayName = line.substr(5); 
            this->makeWorkoutDay(dayName);
        } 

        else if (line.starts_with("Exercise: ")) 
        {
            std::shared_ptr<TrainingDay> currentDay = trainingDays_.back();

            size_t pos = line.find(", Sets: ");
            std::string name = line.substr(10, pos - 10);
            line = line.substr(pos + 8); 

            pos = line.find(", Reps: ");
            size_t sets = std::stoi(line.substr(0, pos));
            line = line.substr(pos + 8); 

            pos = line.find(", Weight: ");
            size_t reps = std::stoi(line.substr(0, pos));
            float weight = std::stof(line.substr(pos + 10)); 

            currentDay->addExercise(name, sets, reps, weight);
        } 

        else if (line == "---") {}
    }
}





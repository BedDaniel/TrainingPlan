#include "../Includes/TrainingPlan.hpp"
#include "../Includes/Menu.hpp"
#include "../Includes/TrainingDay.hpp"
#include <iostream>
 

// std::shared_ptr<TrainingDay> TrainingPlan::makeWorkoutDay(const std::string& name, const std::vector<std::shared_ptr<Exercise>>& exercises) {
//     auto workoutDay = std::make_shared<TrainingDay>(name, exercises);
//     trainingDays_.push_back(workoutDay);
//     return workoutDay;
// }

void TrainingPlan::makeWorkoutDay(const std::string& name) {
    std::vector<std::shared_ptr<Exercise>> emptyExercises;
    trainingDays_.push_back(std::make_shared<TrainingDay>(name, emptyExercises));
}

void TrainingPlan::displayTrainingDays() const {
    for (const auto& trainingDay : trainingDays_) {
        trainingDay->getWorkoutDayName();
    }
}

void TrainingPlan::displayTrainingDaysWithExercises() const {
    for (const auto& trainingDay : trainingDays_) {
        trainingDay->displayTrainingDay(); 
    }
}

void TrainingPlan::removeTrainingDay(int pos) {
    auto iteratorToRemove = trainingDays_.begin() + pos - 1;
    trainingDays_.erase(iteratorToRemove);
}



// void TrainingPlan::displayPlan() const {
//     std::cout << "\nTraining plan: \n";
//     for(int i = 0; i < exercises_.size(); ++i)
//     {
//         std::cout << '\n'<< i+1 << ". ";
//         exercises_[i]->displayExerciseInfo();
//     }
// }

// void TrainingPlan::editExercise(){
//     std::string newName; size_t newReps; size_t newSets; float newWeight;
//     size_t choice = 1;

//     do{
//     system("cls");
//     std::cout << "In which exercise you want to change something?\n";
//     displayPlan();
//     std::cout << "\nInsert a number between 1 - " << exercises_.size() << '\n';
//     system("cls");
//     Menu::validateUserInput(choice); 
//     auto choosenExercise = exercises_[choice];
//     std::cout << "\nYou have choosen the " << exercises_[choice]->getName();
//     std::cout << "\nWhat do you want to change?\n";
//                  "1. Name\n";
//                  "2. Sets\n";
//                  "3. Reps\n";
//                  "4. Load\n";
//                  "0. Well, I don't want to change anything\n";
//     std::cout << "\nInsert a number between 1 - 4" << '\n';

//     switch (choice)
//     {
//     case 1:
//         system("cls");
//         std::cout << "\nWrite the new name of exercise: ";
//         std::getline(std::cin, newName);
//         choosenExercise->setName(newName);
//         system("cls");
//         std::cout << "Done! That is how your exercise looks now:\n";
//         choosenExercise->displayExerciseInfo();
//         break;
//     case 2:
//         system("cls");
//         std::cout << "\nWrite the new amount of reps for " << choosenExercise->getName() << " : ";
//         std::cin >> newReps;
//         choosenExercise->setReps(newReps);
//         system("cls");
//         std::cout << "Done! That is how your exercise looks now:\n";
//         choosenExercise->displayExerciseInfo();
//         break;
//     case 3:
//         system("cls");
//         std::cout << "\nWrite the new amount of sets for " << choosenExercise->getName() << " : ";
//         std::cin >> newSets;
//         choosenExercise->setSets(newSets);
//         system("cls");
//         std::cout << "Done! That is how your exercise looks now:\n";
//         choosenExercise->displayExerciseInfo();
//         break;
//     case 4:
//         system("cls");
//         std::cout << "\nWrite the new amount of load for " << choosenExercise->getName() << " : ";
//         std::cin >> newWeight;
//         choosenExercise->setWeight(newWeight);
//         system("cls");
//         std::cout << "Done! That is how your exercise looks now:\n";
//         choosenExercise->displayExerciseInfo();
//         break;
//     case 0:
//         choice = 0;
//         break;
//     default:
//         std::cout << "\nYou entered an invalid option!";
//         choice = 0;
//         break;
//     }
//     }
//     while(choice != 0);
// }





#include "gtest/gtest.h"
#include <vector>

#include "../Includes/TrainingPlan.hpp"
#include "../Includes/Exercises.hpp"
#include "../Includes/TrainingDay.hpp"

struct TrainingPlanFixture : public ::testing::Test{
    TrainingPlan plan;

    void SetUp() override{

    plan.makeWorkoutDay("Poniedzialek");
    auto& workoutDay = plan.getTrainingDays()[0];
    workoutDay->addExercise("Squats", 2, 0, 50.f);
    workoutDay->addExercise("Pullups", 3, 7, 10.f);
    workoutDay->addExercise("Push ups", 4, 6, 20.f);

    plan.makeWorkoutDay("Czwartek");
    auto& workoutDay2 = plan.getTrainingDays()[1];
    workoutDay2->addExercise("Dips", 5, 4, 30.f);
    workoutDay2->addExercise("DB Press", 5, 7, 10.f);
    workoutDay2->addExercise("Chin Ups", 4, 6, 20.f);
    }
};

TEST_F(TrainingPlanFixture, Make_Workout_Day_Test){
    EXPECT_EQ(plan.getTrainingDays().size(), 2);

}

// TEST_F(TrainingPlanFixture, Add_Exercise_To_Workout_Day_Test) {
//     // Pobierz pierwszy dzień treningowy
//     auto& workoutDay = plan.getTrainingDays()[0];

//     // Sprawdź, czy ćwiczenia zostały dodane do "Poniedziałek"
//     EXPECT_EQ(workoutDay->getExercises().size(), 3);

//     // Pobierz drugi dzień treningowy
//     //auto& workoutDay2 = plan.getTrainingDays()[1];

//     // Sprawdź, czy ćwiczenia zostały dodane do "Czwartek"
//     //EXPECT_EQ(workoutDay2->getExercises().size(), 3);
// }


// TEST_F(TrainingPlanFixture, addExerciseTest){
//     auto vec = plan.getExercise();
//     EXPECT_EQ(vec.size(), 4);
// }

// TEST_F(TrainingPlanFixture, removeExerciseTest2) {
//     plan.removeExercise(2);
//     EXPECT_EQ(plan.getExercise().size(), 3);
// }
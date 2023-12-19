#include "gtest/gtest.h"
#include <vector>

#include "../Includes/TrainingPlan.hpp"
#include "../Includes/Exercises.hpp"
#include "../Includes/TrainingDay.hpp"

struct TrainingPlanFixture : public ::testing::Test{
    TrainingPlan plan;
    TrainingDay day;
    // void SetUp() override{

    // plan.makeWorkoutDay("Poniedzialek");
    // auto& workoutDay = plan.getTrainingDays()[0];
    // workoutDay->addExercise("Squats", 2, 0, 50.f);
    // workoutDay->addExercise("Pullups", 3, 7, 10.f);
    // workoutDay->addExercise("Push ups", 4, 6, 20.f);

    // plan.makeWorkoutDay("Czwartek");
    // auto& workoutDay2 = plan.getTrainingDays()[1];
    // workoutDay2->addExercise("Dips", 5, 4, 30.f);
    // workoutDay2->addExercise("DB Press", 5, 7, 10.f);
    // workoutDay2->addExercise("Chin Ups", 4, 6, 20.f);
    // }
};

// struct TrainingDayFixture : public ::testing::Test{
//     TrainingDay day;
// };

TEST_F(TrainingPlanFixture, MakeWorkoutDay_Correct_Size_And_Name_Test) {
    std::string expectedDayName = "TestDay";
    plan.makeWorkoutDay(expectedDayName);
    // plan.makeWorkoutDay("Poniedzialek");


    auto trainingDays = plan.getTrainingDays();
    ASSERT_EQ(trainingDays.size(), 1);

    auto createdDay = trainingDays[0];
    EXPECT_EQ(createdDay->getWorkoutDayName(), expectedDayName); 
    EXPECT_TRUE(createdDay->getExercises().empty()); 
}

TEST_F(TrainingPlanFixture, AddExercise_Test) {
    std::string exerciseName1 = "Squats";
    size_t sets1 = 3;
    size_t reps1 = 12;
    float weight1 = 50.0f;

    day.addExercise(exerciseName1, sets1, reps1, weight1);

    auto exercises1 = day.getExercises();
    ASSERT_EQ(exercises1.size(), 1);

    auto addedExercise = exercises1.front();
    EXPECT_EQ(addedExercise->getName(), exerciseName1);
    EXPECT_EQ(addedExercise->getSets(), sets1);
    EXPECT_EQ(addedExercise->getReps(), reps1);
    EXPECT_EQ(addedExercise->getWeight(), weight1);

    std::string exerciseName2 = "Pullups";
    size_t sets2 = 3;
    size_t reps2 = 7;
    float weight2 = 10.0f;

    day.addExercise(exerciseName2, sets2, reps2, weight2);

    auto exercises2 = day.getExercises();
    ASSERT_EQ(exercises2.size(), 2); 

    auto addedExercise2 = exercises2.back();
    EXPECT_EQ(addedExercise2->getName(), exerciseName2);
    EXPECT_EQ(addedExercise2->getSets(), sets2);
    EXPECT_EQ(addedExercise2->getReps(), reps2);
    EXPECT_EQ(addedExercise2->getWeight(), weight2);
}

// TEST_F(TrainingPlanFixture, Make_Workout_Day_Test){
//     auto& workoutDay = plan.getTrainingDays()[0];
//     EXPECT_TRUE(workoutDay);
//     auto& workoutDay2 = plan.getTrainingDays()[1];
//     EXPECT_TRUE(workoutDay2);
//     std::cout << plan.getTrainingDays().size();
//     EXPECT_EQ(plan.getTrainingDays().size(), 2);
// }

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
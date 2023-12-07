#include "gtest/gtest.h"
#include <vector>

#include "../Includes/TrainingPlan.hpp"
#include "../Includes/Exercises.hpp"

struct TrainingPlanFixture : public ::testing::Test{
    TrainingPlan plan;

    void SetUp() override{

    plan.addExercise("Squats", 2, 0, 50.f);
    plan.addExercise("Pullups", 3, 7, 10.f);
    plan.addExercise("Push ups", 4, 6, 20.f);
    plan.addExercise("Dips", 5, 4, 30.f);
    }
};

TEST_F(TrainingPlanFixture, addExerciseTest){
    auto vec = plan.getExercise();
    EXPECT_EQ(vec.size(), 4);
}

// TEST_F(TrainingPlanFixture, displayExerciseInfoTest){
//     auto vec = plan.getExercise();
//     EXPECT_EQ(vec[1], 4);
// }

TEST_F(TrainingPlanFixture, removeExerciseTest){
    int choice = 1;
    auto vec = plan.getExercise();
    //EXPECT_EQ(vec.size(), 4);
    plan.removeExercise(2);
    // std::remove(vec.begin(), vec.end(), choice-1);
    // auto newEnd = std::remove(vec.begin(), vec.end(), choice-1);
    // vec.erase(newEnd, vec.end());
    EXPECT_EQ(plan.getExercise().size(), 3);
}
TEST_F(TrainingPlanFixture, removeExerciseTest2) {
    plan.removeExercise(2);
    EXPECT_EQ(plan.getExercise().size(), 3);
}
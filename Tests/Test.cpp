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
    SetUp();
    auto vec = plan.getExercise();
    EXPECT_EQ(vec.size(), 4);
}
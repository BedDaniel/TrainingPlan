#include "../Includes/TrainingPlan.hpp"

int main(){
    TrainingPlan plan;
    plan.addExercise("Squats", 2, 6, 50.f);
    plan.displayPlan();

    return 0;
}
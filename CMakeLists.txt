cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        main # release-1.10.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

project(WorkoutPlan)
enable_testing()

add_executable(${PROJECT_NAME} Src/main.cpp Src/TrainingPlan.cpp Src/Menu.cpp Src/Exercises.cpp Src/TrainingDay.cpp)

add_executable(${PROJECT_NAME}-ut Tests/Test.cpp Src/TrainingPlan.cpp Src/Menu.cpp Src/Exercises.cpp Src/TrainingDay.cpp)

target_link_libraries(${PROJECT_NAME}-ut gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}-ut)
#ifndef WORKOUT_H
#define WORKOUT_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Workout {
public:
    int workoutID;
    string type;
    int duration;
    float caloriesBurned;
    string date;
    int userID;
    string intensityLevel;

    Workout(int id, string t, int dur, float cal, string dt, int uID, string intLvl);
    void addWorkout();
    void removeWorkout();
    void searchWorkout();
    void updateWorkout(string newType, int newDuration, float newCaloriesBurned, string newDate, string newIntensityLevel);
    void viewWorkouts();
    void suggestWorkouts();
    void saveToFile();
    static Workout loadFromFile(int id);
    static void loadAllWorkouts(int userID);
};

#endif // WORKOUT_H

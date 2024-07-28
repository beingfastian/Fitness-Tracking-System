#include "Workout.h"

// Workout Class Methods
Workout::Workout(int id, string t, int dur, float cal, string dt, int uID, string intLvl)
    : workoutID(id), type(t), duration(dur), caloriesBurned(cal), date(dt), userID(uID), intensityLevel(intLvl) {}

void Workout::addWorkout() {
    saveToFile();
    cout << "Workout added: " << type << endl;
}

void Workout::removeWorkout() {
    string filename = "workout_" + to_string(workoutID) + ".txt";
    if (remove(filename.c_str()) == 0) {
        cout << "Workout removed: " << type << endl;
    }
    else {
        cout << "Error removing workout: " << type << endl;
    }
}

void Workout::searchWorkout() {
    cout << "Searching for workout: " << type << endl;
    loadFromFile(workoutID);
}

void Workout::updateWorkout(string newType, int newDuration, float newCaloriesBurned, string newDate, string newIntensityLevel) {
    type = newType;
    duration = newDuration;
    caloriesBurned = newCaloriesBurned;
    date = newDate;
    intensityLevel = newIntensityLevel;
    saveToFile();
    cout << "Workout updated: " << type << endl;
}

void Workout::viewWorkouts() {
    cout << "Viewing workouts" << endl;
    loadAllWorkouts(userID);
}

void Workout::suggestWorkouts() {
    cout << "Suggesting workouts" << endl;
    // Example suggestion logic based on intensity level
    if (intensityLevel == "High") {
        cout << "Suggested Workout: HIIT" << endl;
    }
    else if (intensityLevel == "Medium") {
        cout << "Suggested Workout: Moderate Cardio" << endl;
    }
    else {
        cout << "Suggested Workout: Light Yoga" << endl;
    }
}

void Workout::saveToFile() {
    string filename = "workout_" + to_string(workoutID) + ".txt";
    ofstream outFile(filename.c_str());
    if (outFile.is_open()) {
        outFile << workoutID << endl;
        outFile << type << endl;
        outFile << duration << endl;
        outFile << caloriesBurned << endl;
        outFile << date << endl;
        outFile << userID << endl;
        outFile << intensityLevel << endl;
        outFile.close();
    }
    else {
        cout << "Unable to open file for workout: " << type << endl;
    }
}

Workout Workout::loadFromFile(int id) {
    string filename = "workout_" + to_string(id) + ".txt";
    ifstream inFile(filename.c_str());
    if (inFile.is_open()) {
        int wid, dur, uID;
        float cal;
        string t, dt, intLvl;

        inFile >> wid;
        inFile.ignore();
        getline(inFile, t);
        inFile >> dur;
        inFile >> cal;
        inFile.ignore();
        getline(inFile, dt);
        inFile >> uID;
        inFile.ignore();
        getline(inFile, intLvl);
        inFile.close();
        return Workout(wid, t, dur, cal, dt, uID, intLvl);
    }
    else {
        cout << "Unable to open file for workout ID: " << id << endl;
        return Workout(0, "", 0, 0, "", 0, "");
    }
}

void Workout::loadAllWorkouts(int userID) {
    for (int id = 1; id <= 100; ++id) { // Assume max 100 workouts for simplicity
        string filename = "workout_" + to_string(id) + ".txt";
        ifstream inFile(filename.c_str());
        if (inFile.is_open()) {
            int wid, dur, uID;
            float cal;
            string t, dt, intLvl;

            inFile >> wid;
            inFile.ignore();
            getline(inFile, t);
            inFile >> dur;
            inFile >> cal;
            inFile.ignore();
            getline(inFile, dt);
            inFile >> uID;
            inFile.ignore();
            getline(inFile, intLvl);
            inFile.close();
            if (uID == userID) {
                cout << "Date: " << dt << ", Type: " << t << ", Duration: " << dur << " mins, Calories: " << cal << ", Intensity: " << intLvl << endl;
            }
        }
    }
}

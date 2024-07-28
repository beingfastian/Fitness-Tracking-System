#include "Nutrition.h"

// Nutrition Class Methods
Nutrition::Nutrition(int id, int uID, string dt, string mType, int cal, string macros)
    : mealID(id), userID(uID), date(dt), mealType(mType), calories(cal), macronutrients(macros) {}

void Nutrition::logMeal() {
    saveToFile();
    cout << "Meal logged for user: " << userID << endl;
}

void Nutrition::updateMeal(string newMealType, int newCalories, string newMacros) {
    mealType = newMealType;
    calories = newCalories;
    macronutrients = newMacros;
    saveToFile();
    cout << "Meal updated for user: " << userID << endl;
}

void Nutrition::viewMeals() {
    cout << "Viewing meals for user: " << userID << endl;
    loadAllMeals(userID);
}

void Nutrition::calculateDailyIntake() {
    cout << "Calculating daily intake for user: " << userID << endl;
    int totalCalories = 0;
    for (int id = 1; id <= 100; ++id) { // Assume max 100 meals for simplicity
        string filename = "meal_" + to_string(id) + ".txt";
        ifstream inFile(filename.c_str());
        if (inFile.is_open()) {
            int mid, uID, cal;
            string dt, mType, macros;

            inFile >> mid;
            inFile >> uID;
            inFile.ignore();
            getline(inFile, dt);
            getline(inFile, mType);
            inFile >> cal;
            inFile.ignore();
            getline(inFile, macros);
            inFile.close();
            if (uID == userID) {
                totalCalories += cal;
            }
        }
    }
    cout << "Total Daily Intake: " << totalCalories << " calories" << endl;
}

void Nutrition::suggestMealPlan() {
    cout << "Suggesting meal plan for user: " << userID << endl;
    // Example meal plan suggestion logic
    cout << "Suggested Meal Plan: Balanced diet with 40% carbs, 30% proteins, 30% fats." << endl;
}

void Nutrition::saveToFile() {
    string filename = "meal_" + to_string(mealID) + ".txt";
    ofstream outFile(filename.c_str());
    if (outFile.is_open()) {
        outFile << mealID << endl;
        outFile << userID << endl;
        outFile << date << endl;
        outFile << mealType << endl;
        outFile << calories << endl;
        outFile << macronutrients << endl;
        outFile.close();
    }
    else {
        cout << "Unable to open file for meal: " << date << endl;
    }
}

Nutrition Nutrition::loadFromFile(int id) {
    string filename = "meal_" + to_string(id) + ".txt";
    ifstream inFile(filename.c_str());
    if (inFile.is_open()) {
        int mid, uID, cal;
        string dt, mType, macros;

        inFile >> mid;
        inFile >> uID;
        inFile.ignore();
        getline(inFile, dt);
        getline(inFile, mType);
        inFile >> cal;
        inFile.ignore();
        getline(inFile, macros);
        inFile.close();
        return Nutrition(mid, uID, dt, mType, cal, macros);
    }
    else {
        cout << "Unable to open file for meal ID: " << id << endl;
        return Nutrition(0, 0, "", "", 0, "");
    }
}

void Nutrition::loadAllMeals(int userID) {
    for (int id = 1; id <= 100; ++id) { // Assume max 100 meals for simplicity
        string filename = "meal_" + to_string(id) + ".txt";
        ifstream inFile(filename.c_str());
        if (inFile.is_open()) {
            int mid, uID, cal;
            string dt, mType, macros;

            inFile >> mid;
            inFile >> uID;
            inFile.ignore();
            getline(inFile, dt);
            getline(inFile, mType);
            inFile >> cal;
            inFile.ignore();
            getline(inFile, macros);
            inFile.close();
            if (uID == userID) {
                cout << "Date: " << dt << ", Meal Type: " << mType << ", Calories: " << cal << ", Macronutrients: " << macros << endl;
            }
        }
    }
}

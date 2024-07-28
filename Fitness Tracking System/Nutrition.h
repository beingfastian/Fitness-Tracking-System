#ifndef NUTRITION_H
#define NUTRITION_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Nutrition {
public:
    int mealID;
    int userID;
    string date;
    string mealType;
    int calories;
    string macronutrients; // carbs, proteins, fats

    Nutrition(int id, int uID, string dt, string mType, int cal, string macros);
    void logMeal();
    void updateMeal(string newMealType, int newCalories, string newMacros);
    void viewMeals();
    void calculateDailyIntake();
    void suggestMealPlan();
    void saveToFile();
    static Nutrition loadFromFile(int id);
    static void loadAllMeals(int userID);
};

#endif // NUTRITION_H

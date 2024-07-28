#include <iostream>
#include "User.h"
#include "Workout.h"
#include "Progress.h"
#include "Goal.h"
#include "Insights.h"
#include "Nutrition.h"
#include "Social.h"

using namespace std;

void userMenu();
void workoutMenu();
void progressMenu();
void goalMenu();
void insightsMenu();
void nutritionMenu();
void socialMenu();

int main() {
    int choice;

    do {
        cout << "Fitness Tracking System Menu" << endl;
        cout << "1. User Menu" << endl;
        cout << "2. Workout Menu" << endl;
        cout << "3. Progress Menu" << endl;
        cout << "4. Goal Menu" << endl;
        cout << "5. Insights Menu" << endl;
        cout << "6. Nutrition Menu" << endl;
        cout << "7. Social Menu" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            userMenu();
            break;
        case 2:
            workoutMenu();
            break;
        case 3:
            progressMenu();
            break;
        case 4:
            goalMenu();
            break;
        case 5:
            insightsMenu();
            break;
        case 6:
            nutritionMenu();
            break;
        case 7:
            socialMenu();
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}

void userMenu() {
    int choice;
    do {
        cout << "User Menu" << endl;
        cout << "1. Register User" << endl;
        cout << "2. Remove User" << endl;
        cout << "3. Search User" << endl;
        cout << "4. Update User" << endl;
        cout << "5. Set Goals" << endl;
        cout << "6. View Progress" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        int id, age;
        float weight, height;
        string name, gender, fitnessLevel, goals;
        User user(0, "", 0, 0, 0, "", "");

        switch (choice) {
        case 1:
            cout << "Enter User ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Weight: ";
            cin >> weight;
            cout << "Enter Height: ";
            cin >> height;
            cin.ignore();
            cout << "Enter Gender: ";
            getline(cin, gender);
            cout << "Enter Fitness Level: ";
            getline(cin, fitnessLevel);
            user = User(id, name, age, weight, height, gender, fitnessLevel);
            user.registerUser();
            break;
        case 2:
            cout << "Enter User ID to remove: ";
            cin >> id;
            user = User::loadFromFile(id);
            user.removeUser();
            break;
        case 3:
            cout << "Enter User ID to search: ";
            cin >> id;
            user = User::loadFromFile(id);
            user.searchUser();
            break;
        case 4:
            cout << "Enter User ID to update: ";
            cin >> id;
            user = User::loadFromFile(id);
            cin.ignore();
            cout << "Enter New Name: ";
            getline(cin, name);
            cout << "Enter New Age: ";
            cin >> age;
            cout << "Enter New Weight: ";
            cin >> weight;
            cout << "Enter New Height: ";
            cin >> height;
            cin.ignore();
            cout << "Enter New Gender: ";
            getline(cin, gender);
            cout << "Enter New Fitness Level: ";
            getline(cin, fitnessLevel);
            user.updateUser(name, age, weight, height, gender, fitnessLevel);
            break;
        case 5:
            cout << "Enter User ID to set goals: ";
            cin >> id;
            user = User::loadFromFile(id);
            cin.ignore();
            cout << "Enter goals: ";
            getline(cin, goals);
            user.setGoals(goals);
            break;
        case 6:
            cout << "Enter User ID to view progress: ";
            cin >> id;
            user = User::loadFromFile(id);
            user.viewProgress();
            break;
        case 0:
            cout << "Returning to Main Menu..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}

void workoutMenu() {
    int choice;
    do {
        cout << "Workout Menu" << endl;
        cout << "1. Add Workout" << endl;
        cout << "2. Remove Workout" << endl;
        cout << "3. Search Workout" << endl;
        cout << "4. Update Workout" << endl;
        cout << "5. View Workouts" << endl;
        cout << "6. Suggest Workouts" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        int id, duration, userID;
        float caloriesBurned;
        string type, date, intensityLevel;
        Workout workout(0, "", 0, 0, "", 0, "");

        switch (choice) {
        case 1:
            cout << "Enter Workout ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Type: ";
            getline(cin, type);
            cout << "Enter Duration (minutes): ";
            cin >> duration;
            cout << "Enter Calories Burned: ";
            cin >> caloriesBurned;
            cin.ignore();
            cout << "Enter Date (YYYY-MM-DD): ";
            getline(cin, date);
            cout << "Enter User ID: ";
            cin >> userID;
            cin.ignore();
            cout << "Enter Intensity Level (low, medium, high): ";
            getline(cin, intensityLevel);
            workout = Workout(id, type, duration, caloriesBurned, date, userID, intensityLevel);
            workout.addWorkout();
            break;
        case 2:
            cout << "Enter Workout ID to remove: ";
            cin >> id;
            workout = Workout::loadFromFile(id);
            workout.removeWorkout();
            break;
        case 3:
            cout << "Enter Workout ID to search: ";
            cin >> id;
            workout = Workout::loadFromFile(id);
            workout.searchWorkout();
            break;
        case 4:
            cout << "Enter Workout ID to update: ";
            cin >> id;
            workout = Workout::loadFromFile(id);
            cin.ignore();
            cout << "Enter New Type: ";
            getline(cin, type);
            cout << "Enter New Duration (minutes): ";
            cin >> duration;
            cout << "Enter New Calories Burned: ";
            cin >> caloriesBurned;
            cin.ignore();
            cout << "Enter New Date (YYYY-MM-DD): ";
            getline(cin, date);
            cout << "Enter New Intensity Level (low, medium, high): ";
            getline(cin, intensityLevel);
            workout.updateWorkout(type, duration, caloriesBurned, date, intensityLevel);
            break;
        case 5:
            cout << "Enter User ID to view workouts: ";
            cin >> userID;
            workout.viewWorkouts();
            break;
        case 6:
            cout << "Enter Workout ID to suggest workouts: ";
            cin >> id;
            workout = Workout::loadFromFile(id);
            workout.suggestWorkouts();
            break;
        case 0:
            cout << "Returning to Main Menu..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}

void progressMenu() {
    int choice;
    do {
        cout << "Progress Menu" << endl;
        cout << "1. Log Progress" << endl;
        cout << "2. Update Progress" << endl;
        cout << "3. View Progress" << endl;
        cout << "4. Generate Report" << endl;
        cout << "5. Predict Future Progress" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        int id, userID;
        float weight, BMI, muscleMass, fatPercentage;
        string date;
        Progress progress(0, 0, "", 0, 0, 0, 0);

        switch (choice) {
        case 1:
            cout << "Enter Progress ID: ";
            cin >> id;
            cout << "Enter User ID: ";
            cin >> userID;
            cin.ignore();
            cout << "Enter Date (YYYY-MM-DD): ";
            getline(cin, date);
            cout << "Enter Weight: ";
            cin >> weight;
            cout << "Enter BMI: ";
            cin >> BMI;
            cout << "Enter Muscle Mass: ";
            cin >> muscleMass;
            cout << "Enter Fat Percentage: ";
            cin >> fatPercentage;
            progress = Progress(id, userID, date, weight, BMI, muscleMass, fatPercentage);
            progress.logProgress();
            break;
        case 2:
            cout << "Enter Progress ID to update: ";
            cin >> id;
            progress = Progress::loadFromFile(id);
            cout << "Enter New Weight: ";
            cin >> weight;
            cout << "Enter New BMI: ";
            cin >> BMI;
            cout << "Enter New Muscle Mass: ";
            cin >> muscleMass;
            cout << "Enter New Fat Percentage: ";
            cin >> fatPercentage;
            progress.updateProgress(weight, BMI, muscleMass, fatPercentage);
            break;
        case 3:
            cout << "Enter User ID to view progress: ";
            cin >> userID;
            progress.viewProgress();
            break;
        case 4:
            cout << "Enter User ID to generate report: ";
            cin >> userID;
            progress.generateReport();
            break;
        case 5:
            cout << "Enter User ID to predict future progress: ";
            cin >> userID;
            progress.predictFutureProgress();
            break;
        case 0:
            cout << "Returning to Main Menu..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}

void goalMenu() {
    int choice;
    do {
        cout << "Goal Menu" << endl;
        cout << "1. Set Goal" << endl;
        cout << "2. Update Goal" << endl;
        cout << "3. View Goals" << endl;
        cout << "4. Track Goal Progress" << endl;
        cout << "5. Notify Milestone Achievement" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        int id, userID;
        float target;
        string type, startDate, endDate, status, milestones;
        Goal goal(0, 0, "", 0, "", "", "");

        switch (choice) {
        case 1:
            cout << "Enter Goal ID: ";
            cin >> id;
            cout << "Enter User ID: ";
            cin >> userID;
            cin.ignore();
            cout << "Enter Type: ";
            getline(cin, type);
            cout << "Enter Target: ";
            cin >> target;
            cin.ignore();
            cout << "Enter Start Date (YYYY-MM-DD): ";
            getline(cin, startDate);
            cout << "Enter End Date (YYYY-MM-DD): ";
            getline(cin, endDate);
            cout << "Enter Status (ongoing/completed): ";
            getline(cin, status);
            cout << "Enter Milestones: ";
            getline(cin, milestones);
            goal = Goal(id, userID, type, target, startDate, endDate, status);
            goal.setGoal();
            break;
        case 2:
            cout << "Enter Goal ID to update: ";
            cin >> id;
            goal = Goal::loadFromFile(id);
            cout << "Enter New Target: ";
            cin >> target;
            cin.ignore();
            cout << "Enter New Status (ongoing/completed): ";
            getline(cin, status);
            goal.updateGoal(target, status);
            break;
        case 3:
            cout << "Enter User ID to view goals: ";
            cin >> userID;
            goal.viewGoals();
            break;
        case 4:
            cout << "Enter User ID to track goal progress: ";
            cin >> userID;
            goal.trackGoalProgress();
            break;
        case 5:
            cout << "Enter User ID to notify milestone achievement: ";
            cin >> userID;
            goal.notifyMilestoneAchievement();
            break;
        case 0:
            cout << "Returning to Main Menu..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}

void insightsMenu() {
    int choice;
    do {
        cout << "Insights Menu" << endl;
        cout << "1. Generate Daily Insight" << endl;
        cout << "2. Generate Weekly Insight" << endl;
        cout << "3. Generate Monthly Insight" << endl;
        cout << "4. Provide Recommendations" << endl;
        cout << "5. Analyze Workout Patterns" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        int id, userID;
        string date, summary, recommendations;
        Insights insights(0, 0, "", "", "");

        switch (choice) {
        case 1:
            cout << "Enter Insight ID: ";
            cin >> id;
            cout << "Enter User ID: ";
            cin >> userID;
            cin.ignore();
            cout << "Enter Date (YYYY-MM-DD): ";
            getline(cin, date);
            cout << "Enter Summary: ";
            getline(cin, summary);
            cout << "Enter Recommendations: ";
            getline(cin, recommendations);
            insights = Insights(id, userID, date, summary, recommendations);
            insights.generateDailyInsight();
            break;
        case 2:
            cout << "Enter Insight ID: ";
            cin >> id;
            cout << "Enter User ID: ";
            cin >> userID;
            cin.ignore();
            cout << "Enter Date (YYYY-MM-DD): ";
            getline(cin, date);
            cout << "Enter Summary: ";
            getline(cin, summary);
            cout << "Enter Recommendations: ";
            getline(cin, recommendations);
            insights = Insights(id, userID, date, summary, recommendations);
            insights.generateWeeklyInsight();
            break;
        case 3:
            cout << "Enter Insight ID: ";
            cin >> id;
            cout << "Enter User ID: ";
            cin >> userID;
            cin.ignore();
            cout << "Enter Date (YYYY-MM-DD): ";
            getline(cin, date);
            cout << "Enter Summary: ";
            getline(cin, summary);
            cout << "Enter Recommendations: ";
            getline(cin, recommendations);
            insights = Insights(id, userID, date, summary, recommendations);
            insights.generateMonthlyInsight();
            break;
        case 4:
            cout << "Enter Insight ID: ";
            cin >> id;
            insights = Insights::loadFromFile(id);
            insights.provideRecommendations();
            break;
        case 5:
            cout << "Enter Insight ID: ";
            cin >> id;
            insights = Insights::loadFromFile(id);
            insights.analyzeWorkoutPatterns();
            break;
        case 0:
            cout << "Returning to Main Menu..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}

void nutritionMenu() {
    int choice;
    do {
        cout << "Nutrition Menu" << endl;
        cout << "1. Log Meal" << endl;
        cout << "2. Update Meal" << endl;
        cout << "3. View Meals" << endl;
        cout << "4. Calculate Daily Intake" << endl;
        cout << "5. Suggest Meal Plan" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        int id, userID, calories;
        string date, mealType, macronutrients, macroName;
        Nutrition nutrition(0, 0, "", "", 0, "");

        switch (choice) {
        case 1:
            cout << "Enter Meal ID: ";
            cin >> id;
            cout << "Enter User ID: ";
            cin >> userID;
            cin.ignore();
            cout << "Enter Date (YYYY-MM-DD): ";
            getline(cin, date);
            cout << "Enter Meal Type: ";
            getline(cin, mealType);
            cout << "Enter Calories: ";
            cin >> calories;
            cin.ignore();
            cout << "Enter Macronutrients: ";
            getline(cin, macronutrients);
            nutrition = Nutrition(id, userID, date, mealType, calories, macronutrients);
            nutrition.logMeal();
            break;
        case 2:
            cout << "Enter Meal ID to update: ";
            cin >> id;
            nutrition = Nutrition::loadFromFile(id);
            cin.ignore();
            cout << "Enter New Meal Type: ";
            getline(cin, mealType);
            cout << "Enter New Calories: ";
            cin >> calories;
            cin.ignore();
            cout << "Enter New Macronutrients: ";
            getline(cin, macronutrients);
            nutrition.updateMeal(mealType, calories, macronutrients);
            break;
        case 3:
            cout << "Enter User ID to view meals: ";
            cin >> userID;
            nutrition.viewMeals();
            break;
        case 4:
            cout << "Enter User ID to calculate daily intake: ";
            cin >> userID;
            nutrition.calculateDailyIntake();
            break;
        case 5:
            cout << "Enter User ID to suggest meal plan: ";
            cin >> userID;
            nutrition.suggestMealPlan();
            break;
        case 0:
            cout << "Returning to Main Menu..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}

void socialMenu() {
    int choice;
    do {
        cout << "Social Menu" << endl;
        cout << "1. Create Post" << endl;
        cout << "2. Delete Post" << endl;
        cout << "3. Like Post" << endl;
        cout << "4. Comment on Post" << endl;
        cout << "5. View Posts" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        int id, userID, likes;
        string date, content, comment;
        Social social(0, 0, "", "", 0);

        switch (choice) {
        case 1:
            cout << "Enter Post ID: ";
            cin >> id;
            cout << "Enter User ID: ";
            cin >> userID;
            cin.ignore();
            cout << "Enter Date (YYYY-MM-DD): ";
            getline(cin, date);
            cout << "Enter Content: ";
            getline(cin, content);
            cout << "Enter Likes: ";
            cin >> likes;
            social = Social(id, userID, date, content, likes);
            social.createPost();
            break;
        case 2:
            cout << "Enter Post ID to delete: ";
            cin >> id;
            social = Social::loadFromFile(id);
            social.deletePost();
            break;
        case 3:
            cout << "Enter Post ID to like: ";
            cin >> id;
            social = Social::loadFromFile(id);
            social.likePost();
            break;
        case 4:
            cout << "Enter Post ID to comment on: ";
            cin >> id;
            social = Social::loadFromFile(id);
            cin.ignore();
            cout << "Enter Comment: ";
            getline(cin, comment);
            social.commentOnPost(comment);
            break;
        case 5:
            cout << "Enter User ID to view posts: ";
            cin >> userID;
            social.viewPosts();
            break;
        case 0:
            cout << "Returning to Main Menu..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}

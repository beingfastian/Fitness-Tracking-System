#include "Insights.h"

// Insights Class Methods
Insights::Insights(int id, int uID, string dt, string sum, string rec)
    : insightID(id), userID(uID), date(dt), summary(sum), recommendations(rec) {}

void Insights::generateDailyInsight() {
    saveToFile();
    cout << "Generating daily insight for user: " << userID << endl;
}

void Insights::generateWeeklyInsight() {
    saveToFile();
    cout << "Generating weekly insight for user: " << userID << endl;
}

void Insights::generateMonthlyInsight() {
    saveToFile();
    cout << "Generating monthly insight for user: " << userID << endl;
}

void Insights::provideRecommendations() {
    cout << "Providing recommendations for user: " << userID << endl;
    cout << recommendations << endl;
}

void Insights::analyzeWorkoutPatterns() {
    cout << "Analyzing workout patterns for user: " << userID << endl;
    // Example analysis logic
    if (summary.find("Cardio") != string::npos) {
        recommendations = "Increase strength training to balance your workouts.";
    }
    else {
        recommendations = "Great balance in your workouts!";
    }
    saveToFile();
    cout << recommendations << endl;
}

void Insights::saveToFile() {
    string filename = "insight_" + to_string(insightID) + ".txt";
    ofstream outFile(filename.c_str());
    if (outFile.is_open()) {
        outFile << insightID << endl;
        outFile << userID << endl;
        outFile << date << endl;
        outFile << summary << endl;
        outFile << recommendations << endl;
        outFile.close();
    }
    else {
        cout << "Unable to open file for insight: " << date << endl;
    }
}

Insights Insights::loadFromFile(int id) {
    string filename = "insight_" + to_string(id) + ".txt";
    ifstream inFile(filename.c_str());
    if (inFile.is_open()) {
        int iid, uID;
        string dt, sum, rec;

        inFile >> iid;
        inFile >> uID;
        inFile.ignore();
        getline(inFile, dt);
        getline(inFile, sum);
        getline(inFile, rec);
        inFile.close();
        return Insights(iid, uID, dt, sum, rec);
    }
    else {
        cout << "Unable to open file for insight ID: " << id << endl;
        return Insights(0, 0, "", "", "");
    }
}

void Insights::loadAllInsights(int userID) {
    for (int id = 1; id <= 100; ++id) { // Assume max 100 insights for simplicity
        string filename = "insight_" + to_string(id) + ".txt";
        ifstream inFile(filename.c_str());
        if (inFile.is_open()) {
            int iid, uID;
            string dt, sum, rec;

            inFile >> iid;
            inFile >> uID;
            inFile.ignore();
            getline(inFile, dt);
            getline(inFile, sum);
            getline(inFile, rec);
            inFile.close();
            if (uID == userID) {
                cout << "Date: " << dt << ", Summary: " << sum << ", Recommendations: " << rec << endl;
            }
        }
    }
}

#ifndef INSIGHTS_H
#define INSIGHTS_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Insights {
public:
    int insightID;
    int userID;
    string date;
    string summary;
    string recommendations;

    Insights(int id, int uID, string dt, string sum, string rec);
    void generateDailyInsight();
    void generateWeeklyInsight();
    void generateMonthlyInsight();
    void provideRecommendations();
    void analyzeWorkoutPatterns();
    void saveToFile();
    static Insights loadFromFile(int id);
    static void loadAllInsights(int userID);
};

#endif // INSIGHTS_H

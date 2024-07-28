#ifndef GOAL_H
#define GOAL_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Goal {
public:
    int goalID;
    int userID;
    string type;
    float target;
    string startDate;
    string endDate;
    string status;
    string milestones;

    Goal(int id, int uID, string t, float tgt, string sDate, string eDate, string sts);
    void setGoal();
    void updateGoal(float newTarget, string newStatus);
    void viewGoals();
    void trackGoalProgress();
    void notifyMilestoneAchievement();
    void saveToFile();
    static Goal loadFromFile(int id);
    static void loadAllGoals(int userID);
};

#endif // GOAL_H

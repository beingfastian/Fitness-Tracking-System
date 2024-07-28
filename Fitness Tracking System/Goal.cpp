#include "Goal.h"

// Goal Class Methods
Goal::Goal(int id, int uID, string t, float tgt, string sDate, string eDate, string sts)
    : goalID(id), userID(uID), type(t), target(tgt), startDate(sDate), endDate(eDate), status(sts) {}

void Goal::setGoal() {
    saveToFile();
    cout << "Goal set for user: " << userID << endl;
}

void Goal::updateGoal(float newTarget, string newStatus) {
    target = newTarget;
    status = newStatus;
    saveToFile();
    cout << "Goal updated for user: " << userID << endl;
}

void Goal::viewGoals() {
    cout << "Viewing goals for user: " << userID << endl;
    loadAllGoals(userID);
}

void Goal::trackGoalProgress() {
    cout << "Tracking goal progress for user: " << userID << endl;
    loadAllGoals(userID);
}

void Goal::notifyMilestoneAchievement() {
    cout << "Notifying milestone achievement for user: " << userID << endl;
    loadAllGoals(userID);
}

void Goal::saveToFile() {
    string filename = "goal_" + to_string(goalID) + ".txt";
    ofstream outFile(filename.c_str());
    if (outFile.is_open()) {
        outFile << goalID << endl;
        outFile << userID << endl;
        outFile << type << endl;
        outFile << target << endl;
        outFile << startDate << endl;
        outFile << endDate << endl;
        outFile << status << endl;
        outFile << milestones << endl;
        outFile.close();
    }
    else {
        cout << "Unable to open file for goal: " << type << endl;
    }
}

Goal Goal::loadFromFile(int id) {
    string filename = "goal_" + to_string(id) + ".txt";
    ifstream inFile(filename.c_str());
    if (inFile.is_open()) {
        int gid, uID;
        float tgt;
        string t, sDate, eDate, sts, ml;

        inFile >> gid;
        inFile >> uID;
        inFile.ignore();
        getline(inFile, t);
        inFile >> tgt;
        inFile.ignore();
        getline(inFile, sDate);
        getline(inFile, eDate);
        getline(inFile, sts);
        getline(inFile, ml);
        inFile.close();
        return Goal(gid, uID, t, tgt, sDate, eDate, sts);
    }
    else {
        cout << "Unable to open file for goal ID: " << id << endl;
        return Goal(0, 0, "", 0, "", "", "");
    }
}

void Goal::loadAllGoals(int userID) {
    for (int id = 1; id <= 100; ++id) { // Assume max 100 goals for simplicity
        string filename = "goal_" + to_string(id) + ".txt";
        ifstream inFile(filename.c_str());
        if (inFile.is_open()) {
            int gid, uID;
            float tgt;
            string t, sDate, eDate, sts, ml;

            inFile >> gid;
            inFile >> uID;
            inFile.ignore();
            getline(inFile, t);
            inFile >> tgt;
            inFile.ignore();
            getline(inFile, sDate);
            getline(inFile, eDate);
            getline(inFile, sts);
            getline(inFile, ml);
            inFile.close();
            if (uID == userID) {
                cout << "Type: " << t << ", Target: " << tgt << ", Start Date: " << sDate << ", End Date: " << eDate << ", Status: " << sts << ", Milestones: " << ml << endl;
            }
        }
    }
}

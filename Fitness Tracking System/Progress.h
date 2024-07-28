#ifndef PROGRESS_H
#define PROGRESS_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Progress {
public:
    int progressID;
    int userID;
    string date;
    float weight;
    float BMI;
    float muscleMass;
    float fatPercentage;

    Progress(int id, int uID, string dt, float wt, float bmi, float mm, float fp);
    void logProgress();
    void updateProgress(float newWeight, float newBMI, float newMuscleMass, float newFatPercentage);
    void viewProgress();
    void generateReport();
    void predictFutureProgress();
    void saveToFile();
    static Progress loadFromFile(int id);
    static void loadAllProgress(int userID);
};

#endif // PROGRESS_H

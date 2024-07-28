#include "Progress.h"

// Progress Class Methods
Progress::Progress(int id, int uID, string dt, float wt, float bmi, float mm, float fp)
    : progressID(id), userID(uID), date(dt), weight(wt), BMI(bmi), muscleMass(mm), fatPercentage(fp) {}

void Progress::logProgress() {
    saveToFile();
    cout << "Progress logged for user: " << userID << endl;
}

void Progress::updateProgress(float newWeight, float newBMI, float newMuscleMass, float newFatPercentage) {
    weight = newWeight;
    BMI = newBMI;
    muscleMass = newMuscleMass;
    fatPercentage = newFatPercentage;
    saveToFile();
    cout << "Progress updated for user: " << userID << endl;
}

void Progress::viewProgress() {
    cout << "Viewing progress for user: " << userID << endl;
    loadAllProgress(userID);
}

void Progress::generateReport() {
    cout << "Generating report for user: " << userID << endl;
    string filename = "progress_report_" + to_string(userID) + ".txt";
    ofstream outFile(filename.c_str());
    if (outFile.is_open()) {
        for (int id = 1; id <= 100; ++id) { // Assume max 100 progress records for simplicity
            string pfilename = "progress_" + to_string(id) + ".txt";
            ifstream inFile(pfilename.c_str());
            if (inFile.is_open()) {
                int pid, uID;
                float wt, bmi, mm, fp;
                string dt;

                inFile >> pid;
                inFile >> uID;
                inFile.ignore();
                getline(inFile, dt);
                inFile >> wt;
                inFile >> bmi;
                inFile >> mm;
                inFile >> fp;
                inFile.close();
                if (uID == userID) {
                    outFile << "Date: " << dt << ", Weight: " << wt << ", BMI: " << bmi << ", Muscle Mass: " << mm << ", Fat Percentage: " << fp << endl;
                }
            }
        }
        outFile.close();
    }
    else {
        cout << "Unable to open file for report generation" << endl;
    }
}

void Progress::predictFutureProgress() {
    cout << "Predicting future progress for user: " << userID << endl;
    // Simple prediction logic: Average weight loss per week
    float totalWeightLoss = 0;
    int count = 0;
    for (int id = 1; id <= 100; ++id) { // Assume max 100 progress records for simplicity
        string filename = "progress_" + to_string(id) + ".txt";
        ifstream inFile(filename.c_str());
        if (inFile.is_open()) {
            int pid, uID;
            float wt, bmi, mm, fp;
            string dt;

            inFile >> pid;
            inFile >> uID;
            inFile.ignore();
            getline(inFile, dt);
            inFile >> wt;
            inFile >> bmi;
            inFile >> mm;
            inFile >> fp;
            inFile.close();
            if (uID == userID) {
                if (count > 0) {
                    totalWeightLoss += weight - wt;
                }
                weight = wt;
                count++;
            }
        }
    }
    if (count > 1) {
        float avgWeightLossPerWeek = totalWeightLoss / (count - 1);
        cout << "Average weight loss per week: " << avgWeightLossPerWeek << " kg" << endl;
    }
    else {
        cout << "Not enough data to predict future progress" << endl;
    }
}

void Progress::saveToFile() {
    string filename = "progress_" + to_string(progressID) + ".txt";
    ofstream outFile(filename.c_str());
    if (outFile.is_open()) {
        outFile << progressID << endl;
        outFile << userID << endl;
        outFile << date << endl;
        outFile << weight << endl;
        outFile << BMI << endl;
        outFile << muscleMass << endl;
        outFile << fatPercentage << endl;
        outFile.close();
    }
    else {
        cout << "Unable to open file for progress: " << date << endl;
    }
}

Progress Progress::loadFromFile(int id) {
    string filename = "progress_" + to_string(id) + ".txt";
    ifstream inFile(filename.c_str());
    if (inFile.is_open()) {
        int pid, uID;
        float wt, bmi, mm, fp;
        string dt;

        inFile >> pid;
        inFile >> uID;
        inFile.ignore();
        getline(inFile, dt);
        inFile >> wt;
        inFile >> bmi;
        inFile >> mm;
        inFile >> fp;
        inFile.close();
        return Progress(pid, uID, dt, wt, bmi, mm, fp);
    }
    else {
        cout << "Unable to open file for progress ID: " << id << endl;
        return Progress(0, 0, "", 0, 0, 0, 0);
    }
}

void Progress::loadAllProgress(int userID) {
    for (int id = 1; id <= 100; ++id) { // Assume max 100 progress records for simplicity
        string filename = "progress_" + to_string(id) + ".txt";
        ifstream inFile(filename.c_str());
        if (inFile.is_open()) {
            int pid, uID;
            float wt, bmi, mm, fp;
            string dt;

            inFile >> pid;
            inFile >> uID;
            inFile.ignore();
            getline(inFile, dt);
            inFile >> wt;
            inFile >> bmi;
            inFile >> mm;
            inFile >> fp;
            inFile.close();
            if (uID == userID) {
                cout << "Date: " << dt << ", Weight: " << wt << ", BMI: " << bmi << ", Muscle Mass: " << mm << ", Fat Percentage: " << fp << endl;
            }
        }
    }
}

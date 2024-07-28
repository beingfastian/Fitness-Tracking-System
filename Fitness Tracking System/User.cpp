#include "User.h"
#include "Progress.h"  // Include Progress.h for using Progress class methods

// User Class Methods
User::User(int id, string nm, int ag, float wt, float ht, string gen, string fitLvl)
    : userID(id), name(nm), age(ag), weight(wt), height(ht), gender(gen), fitnessLevel(fitLvl) {}

void User::registerUser() {
    saveToFile();
    cout << "User registered: " << name << endl;
}

void User::removeUser() {
    string filename = "user_" + to_string(userID) + ".txt";
    if (remove(filename.c_str()) == 0) {
        cout << "User removed: " << name << endl;
    }
    else {
        cout << "Error removing user: " << name << endl;
    }
}

void User::searchUser() {
    cout << "Searching for user: " << name << endl;
    loadFromFile(userID);
}

void User::updateUser(string newName, int newAge, float newWeight, float newHeight, string newGender, string newFitnessLevel) {
    name = newName;
    age = newAge;
    weight = newWeight;
    height = newHeight;
    gender = newGender;
    fitnessLevel = newFitnessLevel;
    saveToFile();
    cout << "User updated: " << name << endl;
}

void User::setGoals(string newGoals) {
    goals = newGoals;
    saveToFile();
    cout << "Goals set for user: " << name << endl;
}

void User::viewProgress() {
    cout << "Viewing progress for user: " << name << endl;
    Progress::loadAllProgress(userID);
}

void User::saveToFile() {
    string filename = "user_" + to_string(userID) + ".txt";
    ofstream outFile(filename.c_str());
    if (outFile.is_open()) {
        outFile << userID << endl;
        outFile << name << endl;
        outFile << age << endl;
        outFile << weight << endl;
        outFile << height << endl;
        outFile << gender << endl;
        outFile << fitnessLevel << endl;
        outFile << goals << endl;
        outFile.close();
    }
    else {
        cout << "Unable to open file for user: " << name << endl;
    }
}

User User::loadFromFile(int id) {
    string filename = "user_" + to_string(id) + ".txt";
    ifstream inFile(filename.c_str());
    if (inFile.is_open()) {
        int uid, ag;
        float wt, ht;
        string nm, gen, fitLvl, gls;

        inFile >> uid;
        inFile.ignore();
        getline(inFile, nm);
        inFile >> ag;
        inFile >> wt;
        inFile >> ht;
        inFile.ignore();
        getline(inFile, gen);
        getline(inFile, fitLvl);
        getline(inFile, gls);
        inFile.close();
        return User(uid, nm, ag, wt, ht, gen, fitLvl);
    }
    else {
        cout << "Unable to open file for user ID: " << id << endl;
        return User(0, "", 0, 0, 0, "", "");
    }
}

// PremiumUser Class Methods
PremiumUser::PremiumUser(int id, string nm, int ag, float wt, float ht, string gen, string fitLvl, string mStatus)
    : User(id, nm, ag, wt, ht, gen, fitLvl), membershipStatus(mStatus) {}

void PremiumUser::accessExclusiveWorkouts() {
    cout << "Accessing exclusive workouts for user: " << name << endl;
}

void PremiumUser::receivePersonalizedInsights() {
    cout << "Receiving personalized insights for user: " << name << endl;
}

void PremiumUser::saveToFile() {
    string filename = "premium_user_" + to_string(userID) + ".txt";
    ofstream outFile(filename.c_str());
    if (outFile.is_open()) {
        outFile << userID << endl;
        outFile << name << endl;
        outFile << age << endl;
        outFile << weight << endl;
        outFile << height << endl;
        outFile << gender << endl;
        outFile << fitnessLevel << endl;
        outFile << membershipStatus << endl;
        outFile << exclusiveWorkouts << endl;
        outFile << personalizedInsights << endl;
        outFile.close();
    }
    else {
        cout << "Unable to open file for premium user: " << name << endl;
    }
}

PremiumUser PremiumUser::loadFromFile(int id) {
    string filename = "premium_user_" + to_string(id) + ".txt";
    ifstream inFile(filename.c_str());
    if (inFile.is_open()) {
        int uid, ag;
        float wt, ht;
        string nm, gen, fitLvl, mStatus, exWorkouts, pInsights;

        inFile >> uid;
        inFile.ignore();
        getline(inFile, nm);
        inFile >> ag;
        inFile >> wt;
        inFile >> ht;
        inFile.ignore();
        getline(inFile, gen);
        getline(inFile, fitLvl);
        getline(inFile, mStatus);
        getline(inFile, exWorkouts);
        getline(inFile, pInsights);
        inFile.close();
        return PremiumUser(uid, nm, ag, wt, ht, gen, fitLvl, mStatus);
    }
    else {
        cout << "Unable to open file for premium user ID: " << id << endl;
        return PremiumUser(0, "", 0, 0, 0, "", "", "");
    }
}

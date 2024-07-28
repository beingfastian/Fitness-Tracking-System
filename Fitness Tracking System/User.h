#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class User {
public:
    int userID;
    string name;
    int age;
    float weight;
    float height;
    string gender;
    string fitnessLevel;
    string goals;

    User(int id, string nm, int ag, float wt, float ht, string gen, string fitLvl);
    void registerUser();
    void removeUser();
    void searchUser();
    void updateUser(string newName, int newAge, float newWeight, float newHeight, string newGender, string newFitnessLevel);
    void setGoals(string newGoals);
    void viewProgress();
    void saveToFile();
    static User loadFromFile(int id);
};

class PremiumUser : public User {
public:
    string membershipStatus;
    string exclusiveWorkouts;
    string personalizedInsights;

    PremiumUser(int id, string nm, int ag, float wt, float ht, string gen, string fitLvl, string mStatus);
    void accessExclusiveWorkouts();
    void receivePersonalizedInsights();
    void saveToFile();
    static PremiumUser loadFromFile(int id);
};

#endif // USER_H

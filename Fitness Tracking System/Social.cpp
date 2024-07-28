#include "Social.h"

// Social Class Methods
Social::Social(int id, int uID, string dt, string cnt, int lk)
    : postID(id), userID(uID), date(dt), content(cnt), likes(lk) {}

void Social::createPost() {
    saveToFile();
    cout << "Post created by user: " << userID << endl;
}

void Social::deletePost() {
    string filename = "post_" + to_string(postID) + ".txt";
    if (remove(filename.c_str()) == 0) {
        cout << "Post deleted by user: " << userID << endl;
    }
    else {
        cout << "Error deleting post: " << content << endl;
    }
}

void Social::likePost() {
    likes++;
    saveToFile();
    cout << "Post liked by user: " << userID << endl;
}

void Social::commentOnPost(string comment) {
    comments += comment + "\n";
    saveToFile();
    cout << "Comment added by user: " << userID << endl;
}

void Social::viewPosts() {
    cout << "Viewing posts" << endl;
    loadAllPosts(userID);
}

void Social::saveToFile() {
    string filename = "post_" + to_string(postID) + ".txt";
    ofstream outFile(filename.c_str());
    if (outFile.is_open()) {
        outFile << postID << endl;
        outFile << userID << endl;
        outFile << date << endl;
        outFile << content << endl;
        outFile << likes << endl;
        outFile << comments << endl;
        outFile.close();
    }
    else {
        cout << "Unable to open file for post: " << date << endl;
    }
}

Social Social::loadFromFile(int id) {
    string filename = "post_" + to_string(id) + ".txt";
    ifstream inFile(filename.c_str());
    if (inFile.is_open()) {
        int pid, uID, lk;
        string dt, cnt, cmts;

        inFile >> pid;
        inFile >> uID;
        inFile.ignore();
        getline(inFile, dt);
        getline(inFile, cnt);
        inFile >> lk;
        inFile.ignore();
        getline(inFile, cmts);
        inFile.close();
        return Social(pid, uID, dt, cnt, lk);
    }
    else {
        cout << "Unable to open file for post ID: " << id << endl;
        return Social(0, 0, "", "", 0);
    }
}

void Social::loadAllPosts(int userID) {
    for (int id = 1; id <= 100; ++id) { // Assume max 100 posts for simplicity
        string filename = "post_" + to_string(id) + ".txt";
        ifstream inFile(filename.c_str());
        if (inFile.is_open()) {
            int pid, uID, lk;
            string dt, cnt, cmts;

            inFile >> pid;
            inFile >> uID;
            inFile.ignore();
            getline(inFile, dt);
            getline(inFile, cnt);
            inFile >> lk;
            inFile.ignore();
            getline(inFile, cmts);
            inFile.close();
            if (uID == userID) {
                cout << "Date: " << dt << ", Content: " << cnt << ", Likes: " << lk << ", Comments: " << cmts << endl;
            }
        }
    }
}

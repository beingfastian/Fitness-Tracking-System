#ifndef SOCIAL_H
#define SOCIAL_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Social {
public:
    int postID;
    int userID;
    string date;
    string content;
    int likes;
    string comments;

    Social(int id, int uID, string dt, string cnt, int lk);
    void createPost();
    void deletePost();
    void likePost();
    void commentOnPost(string comment);
    void viewPosts();
    void saveToFile();
    static Social loadFromFile(int id);
    static void loadAllPosts(int userID);
};

#endif // SOCIAL_H

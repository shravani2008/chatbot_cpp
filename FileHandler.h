#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileHandler {
public:
    static void saveChat(const string& user, const string& bot) {
        ofstream file("chat_history.txt", ios::app);
        if(file.is_open()) {
            file << user << endl;
            file << bot << endl;
        }
        file.close();
    }
};

#endif

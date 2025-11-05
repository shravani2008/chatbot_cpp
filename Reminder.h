#ifndef REMINDER_H
#define REMINDER_H

#include <iostream>
#include <string>
using namespace std;

// Reminder class to store tasks, date/time, priority, and status
class Reminder {
    string task;
    string date;
    string priority;
    string status;
public:
    // Constructor to initialize reminder
    Reminder(string t, string d, string p) : task(t), date(d), priority(p), status("Pending") {}

    // Function to display reminder details
    void showReminder() {
        cout << "Task: " << task 
             << " | Date/Time: " << date 
             << " | Priority: " << priority 
             << " | Status: " << status << endl;
    }

    // Getters
    string getTask() const { return task; }
    string getDate() const { return date; }
    string getPriority() const { return priority; }
    string getStatus() const { return status; }

    // Setters
    void setStatus(const string& s) { status = s; }
};

#endif

#include <iostream>
#include <string>
#include "Chatbot.h"
#include "Reminder.h"   // Your original Reminder.h
#include "Calculator.h"
#include "FileHandler.h" // Only for chat history
using namespace std;

int main() {
    Chatbot bot;
    Reminder* reminder = nullptr; // pointer, since we add/delete reminder dynamically
    Calculator calc;

    bot.greet(); // Greet user

    int choice;
    string input;

    do {
        cout << "\n===== Smart Virtual Assistant =====\n";
        cout << "1. Chat with Bot\n";
        cout << "2. Add Reminder\n";
        cout << "3. View Reminder\n";
        cout << "4. Mark Reminder as Done\n";   // NEW OPTION
        cout << "5. Calculator\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // clear newline left in buffer

        switch(choice) {
            case 1: // Chatbot
                while(true) {
                    cout << "\nYou: ";
                    getline(cin, input);
                    if(input == "exit") break; // exit chat
                    string reply = bot.reply(input);
                    cout << "Bot: " << reply << endl;
                    FileHandler::saveChat("You: "+input, "Bot: "+reply); // save chat
                }
                break;

            case 2: // Add Reminder
                {
                    string task, date, priority;
                    cout << "Enter task: ";
                    getline(cin, task);
                    cout << "Enter date/time: ";
                    getline(cin, date);
                    cout << "Enter priority (High/Medium/Low): ";
                    getline(cin, priority);

                    // delete old reminder if exists
                    if(reminder != nullptr) {
                        delete reminder;
                    }

                    // create new reminder
                    reminder = new Reminder(task, date, priority);
                    cout << "Reminder added!\n";
                }
                break;

            case 3: // View Reminder
                if(reminder != nullptr) {
                    reminder->showReminder();
                } else {
                    cout << "No reminder added yet.\n";
                }
                break;

            case 4: // Mark Reminder as Done
                if(reminder != nullptr) {
                    reminder->setStatus("Done");
                    cout << "Reminder marked as Done!\n";
                } else {
                    cout << "No reminder to update.\n";
                }
                break;

            case 5: // Calculator
                calc.run(); // basic + scientific
                break;

            case 6:
                cout << "Exiting... Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Please enter 1-6.\n";
        }

    } while(choice != 6);

    // free memory before exit
    if(reminder != nullptr) {
        delete reminder;
    }

    return 0;
}

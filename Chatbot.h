#ifndef CHATBOT_H
#define CHATBOT_H

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Chatbot {
public:
    void greet() {
        string name;
        cout << "Enter your name: ";
        getline(cin, name);
        cout << "Hello, " << name << "! Nice to meet you.\n";
    }

    string reply(const string& input) {
        string lowerInput = input;
        for(char &c : lowerInput) c = tolower(c); // convert to lowercase

        // Check if input is a number from the menu
        if(lowerInput == "1" || lowerInput == "2" || lowerInput == "3" || lowerInput == "4" || lowerInput == "5") {
            return "Please use the main menu to select this option.";
        }

        // Chatbot responses
        if(lowerInput == "hi" || lowerInput == "hello") return "Hello! How can I help you today?";
        if(lowerInput == "how are you") return "I am a bot, I am always good!";
        if(lowerInput == "tell me a joke") return "Why did the computer show up at work late? It had a hard drive!";
        if(lowerInput == "time") {
            time_t now = time(0);
            return string("Current time is: ") + ctime(&now);
        }

        return "Sorry, I don't understand. Can you ask something else?";
    }
};

#endif


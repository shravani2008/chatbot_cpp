#include <iostream>
using namespace std;

class Calculator {
public:
    void run() {
        string input;
        while (true) {
            cout << "Enter expression (or type 'exit' to go back): ";
            getline(cin, input);

            if (input == "exit") {
                cout << "Returning to main menu...\n";
                break;  // exit the loop
            }

            // Simple calculation example (for demo, replace with your logic)
            // For example, input: 2 + 3
            int num1, num2;
            char op;
            sscanf(input.c_str(), "%d %c %d", &num1, &op, &num2);

            switch(op) {
                case '+': cout << "Result: " << num1 + num2 << endl; break;
                case '-': cout << "Result: " << num1 - num2 << endl; break;
                case '*': cout << "Result: " << num1 * num2 << endl; break;
                case '/':
                    if(num2 == 0) cout << "Cannot divide by zero!" << endl;
                    else cout << "Result: " << num1 / num2 << endl;
                    break;
                default: cout << "Invalid operation!" << endl;
            }
        }
    }
};

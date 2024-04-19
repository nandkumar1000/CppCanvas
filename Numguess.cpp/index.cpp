#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    srand(time(0)); 
    int computerNumber = rand() % 1500 + 1; 
    int userInput;

    while (true) {
        cout << "Enter a number: ";
        cin >> userInput;

        if (userInput > computerNumber) {
            cout << "Your guess is too high" << endl;
            cout << "Computer wins this game. Your guess: " << userInput << ", Computer's number: " << computerNumber << endl;
        } else if (userInput < computerNumber) {
            cout << "Your guess is too low" << endl;
            cout << "Computer wins this game. Your guess: " << userInput << ", Computer's number: " << computerNumber << endl;
        } else {
            cout << "Both of them have the same number" << endl;
            cout << "Computer's number and your guess: " << computerNumber << ", " << userInput << endl;
        }

        cout << "Do you want to play again? (yes/no): ";
        string playAgain;
        cin >> playAgain;

        if (playAgain!= "yes") {
            break;
        }

        computerNumber = rand() % 1200 + 1; 
    }

    return 0;
}
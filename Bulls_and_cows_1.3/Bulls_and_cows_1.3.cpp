#include <iostream>
#include <locale> // tolower
#include <limits>
#include "Header.h"
#include <iomanip>
#define NOMINMAX
#include <Windows.h>


using namespace std;

struct Users {
    string name; //name of the user
    int bestResult; //the best score of the user
    int totalAttempts; //the total amount of attempts
};

Users info[100]{ // not more than 100 users

};

int main()
{
    system("Color 0B"); //make everything aqua
    srand(time(NULL));
    string start = "yes";
    string addNewUser = "user";
    int numberOfUsersZeroBased = -1;
    while ((start == "yes") || (start == "sure") || (start == "certainly") || (start == "of course")) {


        int num1 = 1; //first digit of the answer (for now it is a random number to not leave the variable empty)
        int num2 = 1; //second digit of the answer (for now it is a random number to not leave the variable empty)
        int num3 = 1; //third digit of the answer (for now it is a random number to not leave the variable empty)    
        int num4 = 1; //fourth digit of the answer (for now it is a random number to not leave the variable empty)    
        int guess = 1234; //some random numbers just to not leave the variable empty
        int guess1 = guess % 10;          //first digit of the guess
        int guess2 = guess / 10 % 10;       //second digit of the guess
        int guess3 = guess / 10 / 10 % 10;    //third digit of the guess
        int guess4 = guess / 10 / 10 / 10 % 10; //fourth digit of the guess
        int numberOfCows = 0;
        int numberOfBulls = 0;
        int count = 0; // number of attempts
        int bestScore = 999999;
        string name = "";
        while ((num1 == num2) || (num1 == num3) || (num1 == num4) || (num2 == num3) || (num2 == num4) || (num3 == num4) || (num1 == 0)) {
            num1 = rand() % 10;
            num2 = rand() % 10;
            num3 = rand() % 10;
            num4 = rand() % 10;
        }
        if (addNewUser == "user") {
            cout << "What is your name?\n"; cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); cin >> name;
        }
        cout << num1; cout << num2; cout << num3; cout << num4 << endl; //SHOW THE ANSWER
        cout << "Enter a 4-digit number\n";
        while ((guess1 != num1) || (guess2 != num2) || (guess3 != num3) || (guess4 != num4)) {
            cin >> guess;
            guess4 = guess % 10;
            guess3 = guess / 10 % 10;
            guess2 = guess / 10 / 10 % 10;
            guess1 = guess / 10 / 10 / 10 % 10;
            //Cows
            if (guess1 == num2) {
                numberOfCows++;
            };
            if (guess1 == num3) {
                numberOfCows++;
            };
            if (guess1 == num4) {
                numberOfCows++;
            };
            if (guess2 == num1) {
                numberOfCows++;
            };
            if (guess2 == num3) {
                numberOfCows++;
            };
            if (guess2 == num4) {
                numberOfCows++;
            };
            if (guess3 == num1) {
                numberOfCows++;
            };
            if (guess3 == num2) {
                numberOfCows++;
            };
            if (guess3 == num4) {
                numberOfCows++;
            };
            if (guess4 == num1) {
                numberOfCows++;
            };
            if (guess4 == num2) {
                numberOfCows++;
            };
            if (guess4 == num3) {
                numberOfCows++;
            };
            //Bulls
            if (guess1 == num1) {
                numberOfBulls++;
            };
            if (guess2 == num2) {
                numberOfBulls++;
            };
            if (guess3 == num3) {
                numberOfBulls++;
            };
            if (guess4 == num4) {
                numberOfBulls++;
            };
            // Check if the number satisfies the rules
            if ((guess >= 9999) || (guess <= 1000)) {
                cout << "You can only use 4-digit numbers" << endl;
            }
            else {
                if (numberOfBulls == 1) {
                    cout << numberOfBulls << " bull ";
                }
                else cout << numberOfBulls << " bulls ";
                if (numberOfCows == 1) {
                    cout << "and " << numberOfCows << " cow";
                }
                else cout << "and " << numberOfCows << " cows";
                cout << endl;
                count++;
            }
            numberOfCows = 0;
            numberOfBulls = 0;
        }
        cout << "Congratulations! You won! It took you only " << count << " attempts.\n";
        if (addNewUser == "user") {
            if (count < bestScore) {
                bestScore = count;
                cout << "Your best score is " << bestScore << " attempts. \n";
            }
        }
        else
            for (int i = 0; i < 100; i++) {
                if (addNewUser == info[i].name) {
                    info[i].totalAttempts = info[i].totalAttempts + count;
                    if (count < info[i].bestResult) {
                        info[i].bestResult = count;
                    }
                }
            }
        if (addNewUser == "user") {
            numberOfUsersZeroBased++;
            info[numberOfUsersZeroBased].name = name;
            info[numberOfUsersZeroBased].bestResult = bestScore;
            info[numberOfUsersZeroBased].totalAttempts = count;
        }
        else
            for (int i = 0; i < 100; i++) {
                if (addNewUser == info[i].name) {
                    cout << "Your best score is " << info[i].bestResult << " attempts. \n";
                };
            };
        cout << "Do you want to play one more time?\n";
        cin >> start;
        start = to_lower(start);
        if ((start == "yes") || (start == "sure") || (start == "certainly") || (start == "of course")) {
           cout << "If you want to add more users, type in 'user'. If you want to switch back to your account, type in your name.\n"; cin >> addNewUser;
        }
        
    }
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    for (int i = 0; i < numberOfUsersZeroBased + 1; i++) {
        cout << "The best score of " << info[i].name << " is " << info[i].bestResult << " attempts with total of " << info[i].totalAttempts << " attempts" << endl;
    }
    SetConsoleTextAttribute(h, FOREGROUND_GREEN);
    cout << "\nThanks for playing!";
}
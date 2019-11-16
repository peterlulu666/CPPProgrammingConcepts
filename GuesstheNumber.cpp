#include <iostream>
#include <cmath>
#include <random>
#include <cstring>

using namespace std;
const int TOO_CLOSE_DIFFERENCE = 5;
const int TOO_HIGH_DIFFERENCE = 25;
const int MIN_RANGE = 100;

int main() {
    // You must first prompt the user to enter the low end of the number range.
    cout << "Hold onto your pants, we're about to play guess-the-numbah~ \n";
    cout << "Enter the lowest possible number: ";
    int lowestNumber;
    cin >> lowestNumber;
    // Then prompt the user to enter the high end of the number range.
    int highestNumber;
    while (true) {
        cout << "Enter the highest possible number: ";
        cin >> highestNumber;
        // The high end must be at least 100 more than the low end entered by the user.
        if (highestNumber >= MIN_RANGE + lowestNumber) {
            break;

        } else {
            cout << "High number must be at least 100 more than the low number. \n";

        }
    }
    // Your game must use a random number between LOW and HIGH, inclusively
    // obtain a random number from hardware
    std::random_device rand;
    // seed the generator
    std::mt19937 generate(rand());
    // define the range inclusively
    std::uniform_int_distribution<> distribution(lowestNumber, highestNumber);
    int computerChoose;
    computerChoose = distribution(generate);
    int count = 0;
    while (true) {
        cout << "Pick a number between " << lowestNumber << " and " << highestNumber << ": ";
        int playerChoose;
        cin >> playerChoose;
        // Input is number
        while (cin.fail()) {
            while (cin.get() != '\n') {
                cin.clear();
            }
            cout << "Please enter a number. \n";
            cout << "Pick a number between " << lowestNumber << " and " << highestNumber << ": ";
            cin >> playerChoose;
        }
        count++;
        // You should only accept guesses that are within the range, showing an error message otherwise.
        if (playerChoose < lowestNumber || playerChoose > highestNumber) {
            cout << "Invalid guess. \n";
            continue;

        }
        if (playerChoose == computerChoose) {
            cout << "That's right! " << "You won the game in " << count << " tries. \n";
            break;

        }
        if (playerChoose < computerChoose) {
            if (computerChoose - playerChoose > TOO_HIGH_DIFFERENCE) {
                // it must print "Not even close!" if the number guessed differs from the target by a value of 25 or more.
                cout << "Too low! Not even close! \n";

            }
                // Your game must print "Oooh you're close!" if the number guessed differs from the target by 5 or less.
            else if (computerChoose - playerChoose < TOO_CLOSE_DIFFERENCE) {
                cout << "Too low! Oooh you're close! \n";

            }
                // Your game must print "Too low!" or "Too high!" relative to the target number and the players' guess.
            else {
                cout << "Too low \n";

            }
        }
        if (playerChoose > computerChoose) {
            // it must print "Not even close!" if the number guessed differs from the target by a value of 25 or more.
            if (playerChoose - computerChoose > TOO_HIGH_DIFFERENCE) {
                cout << "Too high! Not even close! \n";

            }
                // Your game must print "Oooh you're close!" if the number guessed differs from the target by 5 or less.
            else if (playerChoose - computerChoose < TOO_CLOSE_DIFFERENCE) {
                cout << "Too high! Oooh you're close! \n";


            }
                // Your game must print "Too low!" or "Too high!" relative to the target number and the players' guess.
            else {
                cout << "Too high \n";

            }
        }


    }


}
#include <iostream>
#include <cmath>
#include <random>

using namespace std;

int main() {
    // The first step is to ask the Human Player what
    // they choose and then repeat back their choice.
    // Players will enter either R for Rock, P for Paper,
    // and S for Scissors.
    cout << "Welcome one and all to a round of Rock, Paper, Scissors! (Enter P, R or S). \n";
    cout << "Player: ";
    string str;
    cin >> str;
    // Wonderful, almost done! Since we are good little programmers,
    // we know that our user may not always follow instructions
    // exactly as we state. We want to handle the situation
    // when the user accidently types a lower case letter.
    // Now the Human Player can enter either R or r for rock, P or p for
    // paper, and S or s for scissors.
    // String to upper case
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    char choose = str.at(0);
    int playerChoose = 0;
    string playerStr;
    switch (choose) {
        case 'R' : {
            cout << "Player choose Rock \n";
            playerChoose = 0;
            playerStr = "Rock";

        }
            break;
        case 'S' : {
            cout << "Player choose Scissors \n";
            playerChoose = 2;
            playerStr = "Scissors";

        }
            break;
        case 'P' : {
            cout << "Player choose Rock \n";
            playerChoose = 0;
            playerStr = "Rock";

        }
            break;
        default:
            cout << "Enter P, R or S";
            break;

    }
    // Now, we must randomly decide what the Computer chooses.
    // To do so, we will randomly generate a number for the computer.
    // The computer has three possible choices and we will represent
    // these three choices by the numbers 0, 1, and 2.
    // obtain a random number from hardware
    std::random_device rand;
    // seed the generator
    std::mt19937 generate(rand());
    // define the range inclusively
    std::uniform_int_distribution<> distribution(0, 2);
    int computerChoose;
    computerChoose = distribution(generate);
//    cout << "Computer choose " << computerChoose;
    // Great! We're one third of the way there.
    // Next, we'll decode what the Computer Player is doing.
    // Instead of displaying 0, 1, or 2,
    // your program should instead print
    // Rock, Paper, or Scissors respectively.
    // At this point, we now will know what each player has thrown.
    string computerStr;
    switch (computerChoose) {
        case 0: {
            cout << "Computer choose Rock \n";
            computerStr = "Rock";

        }
            break;
        case 1: {
            cout << "Computer choose Paper \n";
            computerStr = "Paper";

        }
            break;
        case 2: {
            cout << "Computer choose Scissors \n";
            computerStr = "Scissors";;

        }
            break;
        default:
            break;
            // Add a final line of output that prints a line following this pattern X beats Y. Z wins!
            // Where X and Y are one of "rock" or "scissors" or "paper" and Z is either "Human" or "Computer".
            // Be sure to handle ties appropriately too. And now, we have a fully functioning Rock,
            // Paper, Scissors game! Great job!
    }
    if (playerChoose - computerChoose == 0) {
        cout << "Tie!";

    } else if (playerChoose - computerChoose == -1 || playerChoose - computerChoose == 2) {
        cout << computerStr << " beats " << playerStr << "\n";
        cout << "Computer wins!" << "\n";

    } else {
        cout << playerStr << " beats " << computerStr << "\n";
        cout << "Player wins!" << "\n";

    }


}
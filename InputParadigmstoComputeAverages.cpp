#include <iostream>
#include<fstream>
#include<cmath>

using namespace std;

const double TOLERANCE = 0.000001;

int main() {
    fstream counter_controlled;
    // Counter-Controlled: The first line corresponds to the number of records to follow.
    // The next n lines contain each record.
    counter_controlled.open("/Users/YanzhiWang/CLionProjects/CPPProgrammingConcepts/counter_controlled.txt");
    fstream sentinel_controlled;
    // Sentinel-Controlled: The last line corresponds to the end of records.
    sentinel_controlled.open("/Users/YanzhiWang/CLionProjects/CPPProgrammingConcepts/sentinel_controlled.txt");
    cout << "Which file would you like to open? \n";
    cout << "1. Counter Controlled\n"
            "2. Sentinel Controlled\n";
    int choose = 0;
    cin >> choose;
    int count_counter_controlled = 0;
    int count_Sentinel_Controlled = 0;
    double number = 0.0;
    double sum = 0.0;
    double num = 0.0;
    double sumNum = 0.0;
    switch (choose) {
        case 1:
            // counter_controlled.txt - The first line is an integer denoting how many records follow.
            // Each subsequent line then contains a floating point number.
            counter_controlled >> count_counter_controlled;
            cout << "There are " << count_counter_controlled << " values in the file. \n";
            // For the Counter-Controlled file, you will need to use a for loop to read the file.
            // Think about why a for loop makes the most sense.
            // When you know how many times the loop will run.
            cout << "The values in the file are: \n";
            for (int i = 0; i < count_counter_controlled; ++i) {
                // Starting from the second line.
                counter_controlled >> number;
                cout << number << "\n";
                sum = sum + number;

            }
            cout << "The average is " << sum / count_counter_controlled;
            break;
        case 2:
            // For the Sentinel-Controlled file, you will need to use a while loop to read the file.
            // Think about why a while loop makes the most sense.
            // When you do not know how many times the loop will run.
            cout << "The values in the file are: \n";
            while (true) {
                // sentinel_controlled.txt - Each line contains a floating point number.
                // The last line is denoted by -9999. Use an error threshold of 10^-6 when comparing for equality.
                // Starting from first line.
                sentinel_controlled >> num;
                if (fabs(num + 9999) <= TOLERANCE) {
                    break;

                }
                cout << num << "\n";
                sumNum = sumNum + num;
                count_Sentinel_Controlled++;

            }
            cout << "There are " << count_Sentinel_Controlled << " values in the file. \n";
            cout << "The average is " << sumNum / count_Sentinel_Controlled;
            break;

    }
    counter_controlled.close();
    sentinel_controlled.close();
    return 0;

}
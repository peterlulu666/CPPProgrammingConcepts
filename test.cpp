/* CSCI 261 Lab 4D - Input Paradigms to Compute Averages
 *  Author: Jon Serrano
 *
 */
#include <iostream>
#include<fstream>
#include<cmath>
using namespace std;
int main() {
    fstream cc;
    cc.open("/Users/YanzhiWang/CLionProjects/CPPProgrammingConcepts/counter_controlled.txt");
    if(!cc){
        cerr << "Could not read file counter_controlled";
        return -1;
    }
    fstream sc;
    sc.open("/Users/YanzhiWang/CLionProjects/CPPProgrammingConcepts/sentinel_controlled.txt");
    if(!sc){
        cerr << "Could not read file sentinel controlled";
        return -1;
    }
    cout << "Which file would you like to open?\n1. Counter Controlled\n2. Sentinel Controlled\n>";
    int choice;
    cin >> choice;
    switch(choice){
        case 1:
            int numRecords;
            cc >> numRecords;
            cout << "There are " << numRecords << " values in the file.\n";
            float record;
            float sum;
            for(int i = 0; i <numRecords; i++){
                cc >> record;
                sum += record;
                cout << record << endl;
            }
            cout << "The average is " << (sum /numRecords) << ".";
            break;
        case 2:
            const double TOLERANCE = 0.000001;
            double record2;
            sc >> record2;
            int count;
            float sum2;
            while(!(fabs(record2 + 9999) <= TOLERANCE)){
                cout << record2 << endl;
                sum2 +=record2;
                count++;
                sc >> record2;
            }
            cout << "There are " << count << " values in the file.\n";
            cout << "The average is " << (sum2 /count) << ".";

            break;
    }
    cc.close();
    sc.close();
    return 0;
}
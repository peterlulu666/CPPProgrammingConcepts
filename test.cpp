#include <iostream>
#include <cmath>
#include <random>
#include <cstring>
#include <iomanip>



using namespace std;

int main(){
    double pennies = 1;
    double nickels = 12;
    double dimes = 4;
    double quarters = 120;
    cout << fixed << setprecision(2);
    cout << setw(8) << pennies << " "
    << setw(8) << pennies * 0.01 << "\n";
    cout << setw(8) << nickels << " "
    << setw(8) << nickels * 0.05 << "\n";
    cout << setw(8) << dimes << " "
    << setw(8) << dimes * 0.10 << "\n";
    cout << setw(8) << quarters << " "
    << setw(8) << quarters * 0.25 << "\n";













}
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

int main() {
    string s, str;
    double a = 1.123123;
    std::stringstream ss;
    ss << "a is ";
    ss << fixed << setprecision(2) << a << "\n";
    s = ss.str();
    cout << string(s);
    cout << a;


}
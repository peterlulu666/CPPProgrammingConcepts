#include <iostream>
#include <cstdlib>
#include <random>
#include "effolkronium/random.hpp"

using namespace std;
using Random = effolkronium::random_static;

int main() {
    // obtain a random number from hardware
    std::random_device rand;
    // seed the generator
    std::mt19937 generate(rand());
    // define the range exclusively
    std::uniform_real_distribution<double> distribution(1.0, 10.0);
    // number from 0.0 to 10.0 exclusively
    cout << distribution(generate) << "\n";
    // number from 0 to 10 exclusively
    int a;
    a = distribution(generate);
    cout << a << "\n";
    cout << rand() % 10 << "\n";
    // number from 10 to 20 inclusively
    cout << 10 + rand() % (20 - 10 + 1) << "\n";
    // number from 1 to 10 inclusively
    cout << Random::get(1, 10);


}
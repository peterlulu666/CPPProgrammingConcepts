#include <iostream>
#include <cmath>
#include <random>

using namespace std;

int main() {
    // Your program should prompt the user to
    // enter the three real values.
    const double TOLERANCE = 0.001;
    cout << "enter side a ";
    double sideA;
    cin >> sideA;
    cout << "enter side b ";
    double sideB;
    cin >> sideB;
//    cout << "enter side c ";
//    double sideC;
//    cin >> sideC;
    // Now for the tricky part. We are going to go back and
    // edit what we did at the very beginning. Initially,
    // the user was entering the length of the three sides.
    // Instead, we want to ask the user to enter the first two sides of a triangle.
    // We then need our program to generate a third random real side length that results in a valid triangle.
    // Given the hints above, what can the minimum and maximum possible values be?
    // The rest of the program will then proceed as before using the randomly generated value.
    // Random number in max and min range
    // obtain a random number from hardware
    std::random_device rand;
    // seed the generator
    std::mt19937 generate(rand());
    int max = (int) ((sideA) + sideB);
    int min = (int) (fabs(sideA - sideB));
    // define the range inclusively
    // min + 1 and max + 1 would make it exclusive of the top and bottom value
    std::uniform_int_distribution<> distribution(min + 1, max - 1);
    double sideC;
    sideC = distribution(generate);
    cout << "Side c is " << sideC << "\n";
//        // Random number in max and min range exclusively
//    while (true) {
//        // inclusive of top and bottom value
//        // rand() % (max - min) generate random number from 0 to max - min exclusively
//        // rand() % (max - min + 1) generate random number from 0 to max - min inclusively
//        // rand() % (max - min + 1) + min generate random number from min to max inclusively
//        sideC = (rand() % (max - min + 1)) + min;
//        if (sideC != sideA + sideB && sideC != fabs(sideA - sideB)) {
//            break;
//        }
//    }

    // Swap number
    // Sort number
    // sideA is the smallest side and sideC is the largest side
    if (sideA > sideC) {
        double temp = sideA;
        sideA = sideC;
        sideC = temp;

    }
    if (sideA > sideC) {
        double temp = sideA;
        sideA = sideC;
        sideC = temp;

    }
    if (sideB > sideC) {
        double temp = sideB;
        sideB = sideC;
        sideC = temp;

    }
    // Once done, write code to determine whether the
    // three real value measurements make a triangle.
    // If yes, your program should tell the user whether
    // the triangle is a right, acute, or obtuse triangle.
    // A triangle is possible IFF each side is smaller than the sum of the others.
    bool isTriangle = true;
    if (sideA <= 0 || sideB <= 0 || sideC <= 0 || sideA + sideB <= sideC) {
        cout << "They can not make a triangle. \n";
        isTriangle = false;

    }
        // the triangle is a right triangle if (and only if) a^2 + b^2 == c^2
        // Due to the imprecise nature of double variables,
        // you cannot directly compare two double variables with the == operator.
        // Instead, you should do the comparison using a TOLERANCE constant.
    else if (fabs(pow(sideA, 2) + pow(sideB, 2) - pow(sideC, 2)) <= TOLERANCE) {
        cout << "It is a right triangle. \n";

    }
        // If the triangle is not right, you should then check whether if it is acute (i.e., a^2 + b^2 > c^2).
    else if (pow(sideA, 2) + pow(sideB, 2) > pow(sideC, 2)) {
        cout << "It is an acute triangle. \n";

    }
        // Otherwise, if the triangle is not right or acute,
        // then you can say the triangle is obtuse (i.e., a^2 + b^2 < c^2).
    else if (pow(sideA, 2) + pow(sideB, 2) < pow(sideC, 2)) {
        cout << "It is an obtuse triangle. ";

    }
    // If the result of Part I determines we do have a valid triangle,
    // then we will continue to print out some stats about our triangle.
    // We first will want to print out the three sides in increasing order.
    // Then, we will print out both the perimeter and area of the triangle.
    double perimeter = sideA + sideB + sideC;
    double semiPerimeter = perimeter / 2;
    double area = pow(semiPerimeter * (semiPerimeter - sideA) * (semiPerimeter - sideB) * (semiPerimeter - sideC), 0.5);
    if (isTriangle) {
        cout << "The perimeter is " << perimeter << " and the area is " << area;        
    }

}
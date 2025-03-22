#include <iostream>
#include <cmath>
#include "libquant.h"

using namespace std;

int main() {
    double a, b, c, d;
    Quaternion q1, q2, q3; 
    // input from console, and setter
    input_quant(a, b, c, d);
    q1.set(a, b, c, d);
    cout<<"\nMain quation of Quaternion: "<<endl;
    q1.print();

    // creating quaternion with default parameters.
    q2 = Quaternion();
    cout << "Per default: " << endl;
    q2.print();

    // object copy
    cout << "Copy Q1: " << endl;
    q3 = Quaternion(q1);
    q3.print();
    // getter
    q3.get(a, b, c, d);
    cout << "Coefficients: " << a << b << c << d << endl;

    cout << "\nOperations for Q1:" << endl;
    // quaternion norm
    cout << "\nNorm |q| is " << q1.calculate_norm() << endl;
    // quaternion conjugation
    cout << "Conjugaration:" << endl;
    get_conjugation(q1).print();
    // normalization
    cout << "Normalization: " << endl;
    calculate_normalization(q1).print();
    // invertion
    cout << "Invertion: " << endl;
    q1.calculate_invertion().print();

    q2.set(10, 20, 30, 40);

    // Operations
    cout << "Operations between 2 quternions." << endl;
    cout << "\nQ1: " << endl;
    q1.print();
    cout << "Q2: " << endl;
    q2.print();

    // addition
    cout << "Q1 + Q2:" << endl;
    calculate_addition(q1, q2).print();
    // subtraction
    cout << "Q1 - Q2:" << endl;
    calculate_subtraction(q1, q2).print();
    // multiplication
    cout << "Q1 * Q2:" << endl;
    calculate_multiplication(q1, q2).print();
    // (joy) division
    cout << "Q1 / Q2:" << endl;
    calculate_multiplication(q1, get_conjugation(q2)).print();
    // scalar multiplication
    cout << "scalar Q1 * Q2 = " << calculate_scalar_multiplication(q1, q2) << endl;

    //Euclidian distance
    cout << "d(Q1, Q2) = " << calculate_euclidean(q1, q2) << endl;
    // norm of Chebishev
    cout << "L(Q1, Q2) = " << calculate_norm_2(q1, q2) << endl;
}


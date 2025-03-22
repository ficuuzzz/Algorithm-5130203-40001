
#pragma once


class Quaternion {
    public:
        double aa, bb, cc, dd;

    public:
        Quaternion(double a=1, double b=0, double c=0, double d=0);
        Quaternion(const Quaternion &q);
        ~Quaternion();
        void get(double &a, double &b, double &c, double &d);
        void set(double a, double b, double c, double d);
        void print();
        double calculate_norm();
        Quaternion calculate_invertion();
    };

void input_quant(double &a, double &b, double &c, double &d);
Quaternion get_conjugation(Quaternion q1);
Quaternion calculate_normalization(Quaternion q1);
Quaternion calculate_addition(Quaternion q1, Quaternion q2);
Quaternion calculate_subtraction(Quaternion q1, Quaternion q2);
Quaternion calculate_multiplication(Quaternion q1, Quaternion q2);
double calculate_scalar_multiplication(Quaternion q1, Quaternion q2);
double calculate_euclidean(Quaternion q1, Quaternion q2);
double calculate_norm_2(Quaternion q1, Quaternion q2); 
 


#include <iostream>
#include <cmath>
#include "libquant.h"
using namespace std;

Quaternion::Quaternion(double a, double b, double c, double d) {
    aa=a;
    bb=b;
    cc=c;
    dd=d;
}

Quaternion::Quaternion(const Quaternion &q) {
    aa=q.aa;
    bb=q.bb;
    cc=q.cc;
    dd=q.dd;
}

Quaternion::~Quaternion() {}

void Quaternion::get(double &a, double &b, double &c, double &d) {
    a = aa;
    b = bb;
    c = cc;
    d = dd;
}

void Quaternion::set(double a, double b, double c, double d) {
    aa = a;
    bb = b;
    cc = c;
    dd = d;
}

void input_quant(double &a, double &b, double &c, double &d){
    cout << "Now enter our quanternion." << endl;
    cout<<"a: ";
    cin>>a;
    cout<<"b: ";
    cin>>b;
    cout<<"c: ";
    cin>>c;
    cout<<"c: ";
    cin>>d;
}

void Quaternion::print(){
    cout << "q = " << aa << " + " << bb << "i + " 
    << cc << "j + " << dd << "k" << endl; 
    cout<<endl;
}

double Quaternion::calculate_norm() {
    return sqrt(aa*aa + bb*bb + cc*cc + dd*dd);
}

Quaternion get_conjugation(Quaternion q1) {
    return Quaternion(q1.aa, -1*q1.bb, -1*q1.cc, -1*q1.dd);
}

Quaternion calculate_normalization(Quaternion q1) {
    double n = q1.calculate_norm();
    return Quaternion(q1.aa/n, q1.bb/n, q1.cc/n, q1.dd/n);
}

Quaternion Quaternion::calculate_invertion() {
    double n = pow(calculate_norm(), 2);
    Quaternion q = get_conjugation(*this);
    return Quaternion(q.aa/n, q.bb/n, q.cc/n, q.dd/n);
}

Quaternion calculate_addition(Quaternion q1, Quaternion q2) {
    return Quaternion(q1.aa + q2.aa, q1.bb + q2.bb, q1.cc + q2.cc, q1.dd + q2.dd);
}

Quaternion calculate_subtraction(Quaternion q1, Quaternion q2) {
    return Quaternion(q1.aa - q2.aa, q1.bb - q2.bb, q1.cc - q2.cc, q1.dd - q2.dd);
}
Quaternion calculate_multiplication(Quaternion q1, Quaternion q2) {
    return Quaternion(
        q1.aa * q2.aa - q1.bb * q2.bb - q1.cc * q2.cc - q1.dd * q2.dd,
        q1.aa * q2.bb + q1.bb * q2.aa + q1.cc * q2.dd - q1.dd * q2.cc,
        q1.aa * q2.cc - q1.bb * q2.dd + q1.cc * q2.aa + q1.dd * q2.bb,
        q1.aa * q2.dd + q1.bb * q2.cc - q1.cc * q2.bb + q1.dd * q2.aa
    );
}

double calculate_scalar_multiplication(Quaternion q1, Quaternion q2) {
    return q1.aa * q2.aa + q1.bb * q2.bb + q1.cc * q2.cc + q1.dd * q2.dd;
}

double calculate_euclidean(Quaternion q1, Quaternion q2) {
    return sqrt(pow(q1.aa - q2.aa, 2) + pow(q1.bb - q2.bb, 2) + 
    pow(q1.cc - q2.cc, 2) + pow(q1.dd - q2.dd, 2));
}

double calculate_norm_2(Quaternion q1, Quaternion q2) {
    return max(max(abs(q1.aa - q2.aa), abs(q1.bb - q2.bb)), max(abs(q1.cc - q2.cc), abs(q1.dd - q2.dd)));
}

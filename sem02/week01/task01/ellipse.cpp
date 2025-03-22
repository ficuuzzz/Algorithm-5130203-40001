
#include <iostream>
#include <cmath>
#include "libellipse.h"
using namespace std;

Ellipse::Ellipse(double h, double k, double a, double b){
    hh=h;
    kk=k;
    aa=a;
    bb=b;
}

Ellipse::Ellipse(const Ellipse &e){
    hh = e.hh;
    kk = e.kk;
    aa = e.aa;
    bb = e.bb;
}

Ellipse::~Ellipse(){}

void Ellipse::get(double &h, double &k, double &a, double &b){
    h = hh;
    k = kk;
    a = aa;
    b = bb;
}

void Ellipse::set(double h, double k, double a, double b){
    hh = h;
    kk = k;
    aa = a;
    bb = b;
}

void Ellipse::input_ellipse(double &h, double &k, double &a, double &b){
    
    cout<<"C(h, k): "<<endl;
    cout<<"h: ";
    cin>>h;
    cout<<"k: ";
    cin>>k;
    do{
        cout<<"Enter a (a must be > b): ";
        cin>>a;
        cout<<"b: ";
        cin>>b;
    } while (a < b);
}

void Ellipse::print(){
    cout<<"Main quation of Ellipse: "<<endl;
    cout<<"(x - "<<hh<<")^2/"<<aa*aa<<" + (y - "<<kk<<")^2/"<<bb*bb<<" = 1"<<endl;
    cout<<endl;
}

double Ellipse::calculate_hyperparameter(){
    return sqrt(aa*aa - bb*bb);
}

void Ellipse::calculate_vertexes() {
    cout<<"V1("<<hh-aa<<", "<<kk<<")"<<endl;
    cout<<"V2("<<hh+aa<<", "<<kk<<")"<<endl;
}
void Ellipse::calculate_focuses() {
    double cc = calculate_hyperparameter();
    cout<<"F1("<<hh-cc<<", "<<kk<<")"<<endl;
    cout<<"F2("<<hh+cc<<", "<<kk<<")"<<endl;
}
 
void Ellipse::calculate_characteristic_parametrs() {
    double cc = calculate_hyperparameter();
    cout<<"LR = "<< (2*bb*bb)/aa << endl;
    cout<<"e = "<< cc / aa << endl;
}

void Ellipse::check_point(double x, double y) {
    cout << "P(" << x << ", " << y << ") ";
    if ((pow((x-hh), 2)/(aa*aa) + pow((y-kk), 2)/(bb*bb)) < 1) {
        cout << "is IN the ellipse." << endl;
    } else if ((pow((x-hh), 2)/(aa*aa) + pow((y-kk), 2)/(bb*bb)) == 1) {
        cout << "is ON the ellipse." << endl;
    } else {
        cout << "is OUTSIDE the ellipse." << endl;
    }
}

double Ellipse::calculate_perimeter() {
    return (M_PI * (3*(aa + bb) - sqrt((3*aa + bb) * (aa + 3*bb))));
}

double Ellipse::calculate_area() {
    return (M_PI * aa * bb);
}

void Ellipse::calculate_second_coord(char c, double coord) { 
    if (c == 'x') {
        if (abs(coord) <= aa) {
            cout << "The point is E(" << coord << ", " << (sqrt(pow(bb, 2) *(1 - pow((coord-hh), 2)/(aa*aa))) + kk) << ")";
        } else {
            cout << "There's no that point." << endl;
        }
    } 
    if (c == 'y') {
        if (abs(coord) <= aa) {
            cout << "The point is E(" << (sqrt(pow(aa, 2) *(1 - pow((coord-kk), 2)/(bb*bb))) + hh) << ", " << coord << ")";
        } else {
            cout << "There's no that point." << endl;
        }
    }
}
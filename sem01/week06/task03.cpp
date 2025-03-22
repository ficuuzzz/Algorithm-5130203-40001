#include <iostream>

using namespace std;

struct Point {
    int x;
    int y;
};

int main(){
    struct Point p1, p2;

    p1.x = 10;
    p1.y = 20;


    p2.x = 10;
    p2.y = 40;

    cout << "\nPoint p1 = ";
    cout << "(" << p1.x << ", " << p1.y << ")" << endl;
    cout << "Point p2 = ";
    cout << "(" << p2.x << ", " << p2.y << ")" << endl;
    

    struct Point *p;
    p = &p2;
    p -> x += 100;
    p -> y += 200;
    
    cout << "\nPoint p = ";
    cout << "(" << p -> x << ", " << p -> y << ")" << endl;

    cout << "\nPoint p1 = ";
    cout << "(" << p1.x << ", " << p1.y << ")" << endl;
    cout << "Point p2 = ";
    cout << "(" << p2.x << ", " << p2.y << ")" << endl;

    return 0;;
}
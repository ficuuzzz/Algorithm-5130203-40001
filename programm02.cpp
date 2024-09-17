#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double m, c, v, E, E1;
    m = 9.1 * pow(10, -31);
    c = 2.998 * pow(10, 8);
    cin >> v;
    E = m * pow(c,2) / sqrt(1 - pow(v / c, 2)) - m * pow(c,2);
    E1 = m * pow(v, 2)/2;
    cout << "Ek = " << E << endl;
    cout << "E = " << E1 << endl;
    return 0;
}
#include <iostream>
#include <cmath>
#include "libellipse.h"

using namespace std;

int main (){
    char C;
    double px = 0, py = 0, E = 0, a, b, k, h;
    Ellipse e1;
    Ellipse::input_ellipse(h, k, a, b);
    e1.set(h, k, a, b);

    e1.print();

    cout << "Hyperparameter for 1st ellipse: " 
    << e1.calculate_hyperparameter() << endl;

    cout << "\nVertexes for 1st ellipse: " << endl;
    e1.calculate_vertexes();

    cout << "Focuses for 1st ellipse: " << endl;
    e1.calculate_focuses();

    cout << "\nCharacteristic parameters of ellipsis: " << endl;
    e1.calculate_characteristic_parametrs();

    cout << "\nPerimeter of the Ellipse is " << e1.calculate_perimeter() << endl;
    cout << "Area of the Ellipse is " << e1.calculate_area() << endl;

    cout << "\nEnter the point with x, y coordinates:" << endl;
    cout << "x: ";
    cin >> px;
    cout << "y: ";
    cin >> py;
    cout << endl;
    e1.check_point(px, py);

    cout << "\nEnter the one coordinate for point E." << endl;
    do {
        cout << "What coordinate is this [x/y]? ";
        cin >> C;
    } while (C != 'x' && C != 'y');
    cout << "Enter the value of " << C << ": ";
    cin >> E;
    e1.calculate_second_coord(C, E);

    
    return 0;
}

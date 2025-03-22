#include <iostream>
#include <cmath>
using namespace std;

struct Vector {
    double x;
    double y;
    double z;
};
struct Vector create_vector();
void print_vector(struct Vector v);
struct Vector operate_vector(struct Vector v1, struct Vector v2);

int main(){
    struct Vector v1, v2, vres;

   cout << "\nInput vector 1: " << endl;
   v1 = create_vector();
   cout << "\nInput vector 2: " << endl;
   v2 = create_vector();
   
    cout << "Vector 1: " << endl;
    print_vector(v1);
    cout << "Vector 2: " << endl;
    print_vector(v2);

    vres = operate_vector(v1, v2); 
    cout << "Vector (2 * vector1 + 3 * vector2): " << endl;
    print_vector(vres);

    return 0;
}

struct Vector create_vector() {
    struct Vector v;

    cout << "\nX:";
    cin >> v.x;
    cout << "\nY:";
    cin >> v.y;
    cout << "\nZ:";
    cin >> v.z;

    return v;
}

void print_vector(struct Vector v) {
    
    cout << "X: " << v.x << endl;
    cout << "Y: " << v.y << endl;
    cout << "Z: " << v.z << endl;
}

struct Vector operate_vector(struct Vector v1, struct Vector v2) {
    struct Vector result;

    result.x = 2 * (v1.x) + 3 * (v2.x);
    result.y = 2 * (v1.y) + 3 * (v2.y);
    result.z = 2 * (v1.z) + 3 * (v2.z);
    
    return result;
}
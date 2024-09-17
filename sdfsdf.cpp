#include <iostream>


using namespace std;

int main()
{
    double salary, years;
    string concepts;
    cout << "***PROGRAM 04***" << endl;
    cout << "Base salary: ";
    cin >> salary;
    cout << "Years of service: ";
    cin >> years;
    cout << "Concepts: ";
    cin >> concepts;
    if (years >= 1 && years <= 5) {
        salary = salary + salary * 0.1;
    }
    else {
        salary = salary + salary * 0.15;
    }
    if (concepts == "boss") {
        salary = salary + salary * 0.1;
    }
    else if (concepts == "high education") {
        salary = salary + salary * 0.05;
    }
    else if (concepts == "phd") {
        salary = salary + salary * 0.12;
    }
    cout << salary << endl;
}
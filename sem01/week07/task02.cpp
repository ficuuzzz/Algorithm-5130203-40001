#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

struct Student {
    int code80;
    char name[50];
    bool status;
    double math, physics, programming;
};

void define_num_students(int *x);
void print_student(struct Student s);
void insert_student(struct Student *s);
void insert_vect_students(int n, struct Student *lst_student);

int main () {
    int n;
    struct Student *lst_student;
    define_num_students(&n);
    
    lst_student = new Student[n];

    cout << "****Insert students****" << endl;
    insert_vect_students(n, lst_student);


    return 0;
}

void define_num_students(int *x) {
    do {
        cout << "Number of students" << endl;
        cin >> *x;
    }while (x < 0); 
    
}

void insert_vect_students(int n, struct Student *lst_student) {
    for (int i = 0; i < n; i++) {
        insert_student(&lst_student[i]);
    }
}
void insert_student(struct Student *s) {
    int num_students = s->code80;
    cout << "Student " << num_students;
    cout << "Name: ";
    cin >> s->name;
    cout << "Status [0-scholarship, 1-contract]: ";
    cin >> s->status;
    cout << "Score in math: ";
    cin >> s->math;
    cout << "Score in physics: ";
    cin >> s->physics;
    cout << "Score in programming: ";
    cin >> s->programming;
    num_students++;
}

void print_vec_students(int n, struct Student *lst_student) {
    cout << left;
    for(int i = 0; i < n; i++) {
        print_student(lst_student[i]);
    }
}

void print_student(struct Student s) {
    cout << left;
    cout << s.code80 << setw(10) << endl;
}
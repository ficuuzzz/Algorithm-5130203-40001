

#pragma once


class Ellipse{
    public:
        double hh, kk, aa, bb;

    public:
        Ellipse(double h=0, double k=0, double a=0, double b=0);
        Ellipse(const Ellipse &e);
        ~Ellipse();
        void get(double &h, double &k, double &a, double &b);
        void set(double h, double k, double a, double b);
        static void input_ellipse(double &h, double &k, double &a, double &b);
        void print();
        double calculate_hyperparameter();
        double calculate_perimeter();
        double calculate_area();
        void calculate_vertexes();
        void calculate_focuses();
        void calculate_characteristic_parametrs();
        void check_point(double x, double y);
        void calculate_second_coord(char c, double coord);
};
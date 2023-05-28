#include <iostream>
using namespace std;

class Quadrilateral {
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
};

class Square : public Quadrilateral {
private:
    double side;
public:
    Square(double s) {
        side = s;
    }
    double area() {
        return side * side;
    }
    double perimeter() {
        return 4 * side;
    }
};

class Rectangle : public Quadrilateral {
private:
    double length, width;
public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }
    double area() {
        return length * width;
    }
    double perimeter() {
        return 2 * (length + width);
    }
};

class Parallelogram : public Quadrilateral {
private:
    double base, height, side;
public:
    Parallelogram(double b, double h, double s) {
        base = b;
        height = h;
        side = s;
    }
    double area() {
        return base * height;
    }
    double perimeter() {
        return 2 * (base + side);
    }
};

class Trapezoid : public Quadrilateral {
private:
    double base1, base2, height, side1, side2;
public:
    Trapezoid(double b1, double b2, double h, double s1, double s2) {
        base1 = b1;
        base2 = b2;
        height = h;
        side1 = s1;
        side2 = s2;
    }
    double area() {
        return 0.5 * (base1 + base2) * height;
    }
    double perimeter() {
        return base1 + base2 + side1 + side2;
    }
};

int main() {
    Square sq(5);
    cout << "Area of square: " << sq.area() << endl;
    cout << "Perimeter of square: " << sq.perimeter() << endl;

    Rectangle rect(4, 6);
    cout << "Area of rectangle: " << rect.area() << endl;
    cout << "Perimeter of rectangle: " << rect.perimeter() << endl;

    Parallelogram para(5, 8, 6);
    cout << "Area of parallelogram: " << para.area() << endl;
    cout << "Perimeter of parallelogram: " << para.perimeter() << endl;

    Trapezoid trap(5, 8, 6, 7, 9);
    cout << "Area of trapezoid: " << trap.area() << endl;
    cout << "Perimeter of trapezoid: " << trap.perimeter() << endl;

    return 0;
}
#include <iostream>
#include <Windows.h>
using namespace std;
// Без віртуального успадкування
class Base {
public:
    int base_data;
};

class Derived1 : public Base {
public:
    int derived1_data;
};

class Derived2 : public Base {
public:
    int derived2_data;
};

class Derived3 : public Derived1 {
public:
    int derived3_data;
};

class Derived4 : public Derived2 {
public:
    int derived4_data;
};

class Derived5 : public Derived3, public Derived4, public Derived2 {
public:
    int derived5_data;
};

// З віртуальним успадкуванням
class VBase {
public:
    int vbase_data;
};

class VDerived1 : virtual public VBase {
public:
    int vderived1_data;
};

class VDerived2 : virtual public VBase {
public:
    int vderived2_data;
};

class VDerived3 : virtual public VDerived1 {
public:
    int vderived3_data;
};

class VDerived4 : virtual public VDerived2 {
public:
    int vderived4_data;
};

class VDerived5 : virtual public VDerived3, virtual public VDerived4, virtual public VDerived2 {
public:
    int vderived5_data;
};

int main() {
    SetConsoleOutputCP(1251);
    Derived1 d1;
    Derived2 d2;
    Derived3 d3;
    Derived4 d4;
    Derived5 d5;
    VDerived1 vd1;
    VDerived2 vd2;
    VDerived3 vd3;
    VDerived4 vd4;
    VDerived5 vd5;

    cout << "Розмір об'єкта Derived1 (без віртуального успадкування): " << sizeof(d1) << endl;
    cout << "Розмір об'єкта Derived2 (без віртуального успадкування): " << sizeof(d2) << endl;
    cout << "Розмір об'єкта Derived3 (без віртуального успадкування): " << sizeof(d3) << endl;
    cout << "Розмір об'єкта Derived4 (без віртуального успадкування): " << sizeof(d4) << endl;
    cout << "Розмір об'єкта Derived5 (без віртуального успадкування): " << sizeof(d5) << endl;
    cout << "Розмір об'єкта VDerived1 (з віртуальним успадкуванням): " << sizeof(vd1) << endl;
    cout << "Розмір об'єкта VDerived2 (з віртуальним успадкуванням): " << sizeof(vd2) << endl;
    cout << "Розмір об'єкта VDerived3 (з віртуальним успадкуванням): " << sizeof(vd3) << endl;
    cout << "Розмір об'єкта VDerived4 (з віртуальним успадкуванням): " << sizeof(vd4) << endl;
    cout << "Розмір об'єкта VDerived5 (з віртуальним успадкуванням): " << sizeof(vd5) << endl;

    return 0;
}
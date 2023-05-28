#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) {
        name = n;
        age = a;
    }
    virtual ~Person() {}
    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
    friend istream& operator>>(istream& in, Person& p) {
        cout << "Enter name: ";
        in >> p.name;
        cout << "Enter age: ";
        in >> p.age;
        return in;
    }
    friend ostream& operator<<(ostream& out, const Person& p) {
        out << "Name: " << p.name << endl;
        out << "Age: " << p.age << endl;
        return out;
    }
};

class Father : public virtual Person {
protected:
    int income;
public:
    Father(string n, int a, int i) : Person(n, a) {
        income = i;
    }
    virtual ~Father() {}
    virtual void display() {
        Person::display();
        cout << "Income: " << income << endl;
    }
    friend istream& operator>>(istream& in, Father& f) {
        Person& p = f;
        in >> p;
        cout << "Enter income: ";
        in >> f.income;
        return in;
    }
    friend ostream& operator<<(ostream& out, const Father& f) {
        const Person& p = f;
        out << p;
        out << "Income: " << f.income << endl;
        return out;
    }
};

class Mother : public virtual Person {
protected:
    int education;
public:
    Mother(string n, int a, int e) : Person(n, a) {
        education = e;
    }
    virtual ~Mother() {}
    virtual void display() {
        Person::display();
        cout << "Education level: " << education << endl;
    }
    friend istream& operator>>(istream& in, Mother& m) {
        Person& p = m;
        in >> p;
        cout << "Enter education level: ";
        in >> m.education;
        return in;
    }
    friend ostream& operator<<(ostream& out, const Mother& m) {
        const Person& p = m;
        out << p;
        out << "Education level: " << m.education << endl;
        return out;
    }
};

class Son : public Father, public Mother {
protected:
    string hobby;
public:
    Son(string n, int a, int i, int e, string h) : Person(n, a), Father(n, a, i), Mother(n, a, e) {
        hobby = h;
    }
    virtual ~Son() {}
    virtual void display() {
        Father::display();
        Mother::display();
        cout << "Hobby: " << hobby << endl;
    }
    friend istream& operator>>(istream& in, Son& s) {
        Father& f = s;
        Mother& m = s;
        in >> f;
        in >> m;
        cout << "Enter hobby: ";
        in >> s.hobby;
        return in;
    }
    friend ostream& operator<<(ostream& out, const Son& s) {
        const Father& f = s;
        const Mother& m = s;
        out << f;
        out << m;
        out << "Hobby: " << s.hobby << endl;
        return out;
    }
};

int main() {
    Son s("John", 20, 50000, 4, "Playing football");
    cout << "Son's information:" << endl;
    s.display();
    cout << endl;

    Son s2("Mary", 18, 45000, 5, "Playing guitar");
    cout << "Enter information for second son:" << endl;
    cin >> s2;
    cout << "Second son's information:" << endl;
    cout << s2 << endl;

    return 0;
}
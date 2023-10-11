#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Writer {
    void (*write)(const char *str);
    //void (*read)(const char *str);
};
void write_simple(const char *str) {
    cout << str << endl;
}
void write_with_prefix(const char *str) {
    cout << "Received std: " << std::quoted(str) << endl;
}
Writer make_simple() {
    return Writer{.write = write_simple};
}
Writer make_with_prefix() {
    return Writer{.write = write_with_prefix};
}

//struct CppWriter {
//    virtual void write (const char *str) = 0;
//};

struct CBase {
    int base_value;
};
struct CDerived {
    CBase base;
    double derived_value;
};

struct Base {
    int base_value;
};
struct Derived : public Base {
    double derived_value;
};

struct Point {
    int x;
    int y;
};
ostream& operator<<(ostream &stream, const Point &point) {
    stream << "Point {x: " << point.x << ", y: " << point.y << "}";
    return stream;
}

int main () {
    Point p {1, 20};
    cout << p << endl << endl;
    cout << "hello";
    const char *str1 = "Hello, ";
    const char *str2 = "world";
    //const char *str3 = str1 + str2;
    string s1 = "hello, ";
    string s2 = "world";
    string hello_world = s1 + s2;
    cout << "sum result: " << std::quoted(hello_world) << endl;

    int arr[] = {1, 2, 3};
    int const *       pointer_to_const = &arr[0];
    int       * const const_pointer    = &arr[0];
    //arr++;

    //*pointer_to_const = 1;
    pointer_to_const++;
    *const_pointer = 1;
    //const_pointer++;

    int a = 3;
#include "header.hpp"
    cout << a;

    cout << endl << endl;
    int choice_if_prefix = 0;
    cout << "Enter non-0 to use prefix: ";
    cin >> choice_if_prefix;
    Writer object;
    if (choice_if_prefix) {
        object = make_with_prefix();
    }
    else {
        object = make_simple();
    }
    object.write("MY STRING");

    return 0;
}

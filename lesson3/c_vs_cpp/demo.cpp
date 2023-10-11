#include "demo_bruteforce.h"
#include "demo_cpp.h"
#include "demo_inheritance.h"

#include <iostream>
using namespace std;


int main () {
    // Интерфейсы, грубо и в стиле C++
    //demo_interface_bruteforce::run_demo();
    //demo_interface_cpp::run_demo();

    // Наследование, как разрешаются вызовы
    demo_inheritance::run_demo();

    return 0;
}

#ifndef _DEMO_INHERITANCE_H_
#define _DEMO_INHERITANCE_H_

#include <iostream>
#include <memory>

namespace demo_inheritance {
    struct Base {
        static const unsigned COUNT = 10;

        const char *my_name;

        int *dyn_array;
        Base (const char *new_name) : my_name(new_name)
        {
            std::cout << "- Base(\"" << new_name << "\"): constructor called\n";
            dyn_array = new int[COUNT];
            for (unsigned i = 0; i < COUNT; i++) {
                dyn_array[i] = i;
            }
        }
        virtual void print_name () {
            std::cout << "Base(\"" << my_name << "\")";
        }
        virtual void print () {
            std::cout << "Base{";
            for (unsigned i = 0; i < COUNT; i++) {
                if (i != 0) {
                    std::cout << ", ";
                }
                std::cout << dyn_array[i];
            }
            std::cout << "}";
        }
        // ВАМОЕ ВАЖНОЕ ЗА ЭТО ЗАНЯТИЕ - ВИРТУАЛЬНЫЙ
        // ДЕСТРУКТОР
        virtual ~Base() {
            std::cout << "- Base(\"";print_name();
            std::cout << "\"): destructor called\n";
            delete [] dyn_array;
        }
    };

    struct Derived : public Base {
        static const unsigned COUNT = 5;

        int *dyn_array;
        Derived (const char *new_name) : Base(new_name)
        {
            std::cout << "- Derived(\"" << new_name << "\"): constructor called\n";
            dyn_array = new int[COUNT];
            for (unsigned i = 0; i < COUNT; i++) {
                dyn_array[i] = 10*i;
            }
        }
        virtual void print_name () {
            std::cout << "Derived(\"" << my_name << "\")";
        }
        virtual void print () {
            std::cout << "Derived{";
            Base::print();
            std::cout << "{";
            for (unsigned i = 0; i < COUNT; i++) {
                if (i != 0) {
                    std::cout << ", ";
                }
                std::cout << dyn_array[i];
            }
            std::cout << "}}";
        }
        ~Derived() {
            std::cout << "- Derived(\"";print_name();
            std::cout << "\"): destructor called\n";
            delete [] dyn_array;
        }
    };

    // Приводить к базовому классу можно не только указатели,
    // но и ссылки

    void run_demo () {
        // создание unique_ptr через new
        std::cout << "Make Base('0')\n";
        std::unique_ptr<Base> obj0(new Base("obj0"));

        // создание unique_ptr через make_unique,
        // а также первая демонстрация базового и производного класса
        std::cout << "Make Base('1')\n";
        std::unique_ptr<Base> obj1 = std::make_unique<Base>("obj1");
        std::cout << "Make Derived('2')\n";
        std::unique_ptr<Base> obj2 = std::make_unique<Derived>("obj2");

        std::cout << "\n";

        // Array
        std::cout << "Array of ";obj1->print_name();
        std::cout<< " is ";obj1->print();std::cout << '\n';

        std::cout << "Array of ";obj2->print_name();
        std::cout<< " is ";obj2->print();std::cout << '\n';

        std::cout << '\n';
    }
}

#endif // _DEMO_INHERITANCE_H_

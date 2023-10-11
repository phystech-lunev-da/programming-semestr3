#ifndef _DEMO_BRUTEFORCE_H_
#define _DEMO_BRUTEFORCE_H_

#include <iostream>
#include <fstream>
#include <cstdint>
#include <string>
//using namespace std;

namespace demo_interface_bruteforce {

    struct Interface {
        void (*write_str) (Interface *this_obj, const char *str);
    };

    struct ConsoleImplementation {
        Interface interface;

        static void write_str_to_console (Interface *this_obj, const char *str) {
            std::cout << "String is \"" << str << "\"";
        }
        ConsoleImplementation ()
            : interface(Interface{
                    .write_str = ConsoleImplementation::write_str_to_console
                    })
        {}
    };

    struct FileImplementation {
        Interface interface;
    private:
        std::ofstream stream;
    public:

        static void write_str_to_file (Interface *this_obj, const char *str) {
            // &FileImplementation::interface == &FileImplementation
            FileImplementation *as_file = reinterpret_cast<FileImplementation*>(this_obj);

            as_file->stream
            // как в cout
                   << str;
            // Point   point; //   point.x
            // Point   point; //   point.print_me()
            // Point  *point; //   point->x
            // Point  *point; //   point->print_me()
            // Point **point; // (*point)->x
            // Point **point; // (*point)->print_me()
            as_file->stream.close();
        }
        FileImplementation (const char *filename)
            : interface(Interface{
                    .write_str = FileImplementation::write_str_to_file
                    }),
              stream(filename, std::ios::out)
        {}
    };

    void run_demo() {
        Interface *my_interface = nullptr;
        bool shall_use_file = false;

        std::cout << "Shall we use file? Enter 1 or 0: ";
        std::cin >> shall_use_file;

        if (shall_use_file) {
            // file impl
            uint8_t *file_bytes = new uint8_t[sizeof(FileImplementation)];
            FileImplementation *ptr_as_file = reinterpret_cast<FileImplementation*>(file_bytes);
            // не работает:
            // *ptr_as_file = FileImplementation("myfile.txt");
            // надо так - с помощью такого new
            // вызвать конструктор на уже выделенном, заранее,
            // участке памяти:
            new(ptr_as_file) FileImplementation("myfile.txt");
            my_interface = &ptr_as_file->interface;
        }
        else {
            // console impl
            uint8_t *console_bytes = new uint8_t[sizeof(ConsoleImplementation)];
            ConsoleImplementation *ptr_as_console = reinterpret_cast<ConsoleImplementation*>(console_bytes);
            *ptr_as_console = ConsoleImplementation();
            my_interface = &ptr_as_console->interface;
        }
        // ...
        std::string value;
        std::cout << "Enter string to write: ";
        std::cin.ignore();
        std::getline(std::cin, value);
        // всё делалось ради этого:
        my_interface->write_str(my_interface, value.data());
        delete[] reinterpret_cast<uint8_t*>(my_interface);
    }

}

#endif // _DEMO_BRUTEFORCE_H_

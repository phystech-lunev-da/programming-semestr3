#ifndef _DEMO_CPP_H_
#define _DEMO_CPP_H_

#include <iostream>
#include <fstream>
#include <string>

namespace demo_interface_cpp {

    struct Interface {
        virtual void write_str (const char *str) = 0;
    };

    struct ConsoleImplementation : public Interface {
        void write_str (const char *str) override {
            std::cout << "String is \"" << str << "\"";
        }
    };

    struct FileImplementation : public Interface {
    private:
        std::ofstream stream;
    public:

        void write_str (const char *str) override final {
            this->stream << str;
            this->stream.close();
        }
        FileImplementation (const char *filename)
            : stream(filename, std::ios::out)
        {}
    };

    void run_demo() {
        Interface *my_interface = nullptr;
        bool shall_use_file = false;

        std::cout << "Shall we use file? Enter 1 or 0: ";
        std::cin >> shall_use_file;

        if (shall_use_file) {
            my_interface = new FileImplementation("myfile.txt");
        }
        else {
            //my_interface = new ConsoleImplementation;
            ConsoleImplementation *my_console = new ConsoleImplementation;
            my_interface = my_console;
        }
        // ...
        std::string value;
        std::cout << "Enter string to write: ";
        std::cin.ignore();
        std::getline(std::cin, value);
        // всё делалось ради этого:
        my_interface->write_str(value.data());

        delete my_interface;
    }

}

#endif // _DEMO_CPP_H_

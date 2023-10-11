
#include <iostream>

struct Writer
{
    void(*write)(const char* str);
};

Writer create_simple();
Writer create_prefix();

void write_simple(const char* str);
void write_prefix(const char* str);

int main()
{
    Writer simple = create_simple();
    Writer prefix = create_prefix();

    simple.write("Hello, world");
    prefix.write("Hello, world");
}

Writer create_simple()
{
    Writer new_writer{write_simple};
    return new_writer;
}

Writer create_prefix()
{
    Writer new_writer{write_prefix};
    return new_writer;
}

void write_simple(const char* str)
{
    std::cout << str << std::endl;
}

void write_prefix(const char* str)
{
    std::cout << "Attention! " << str << std::endl;
}
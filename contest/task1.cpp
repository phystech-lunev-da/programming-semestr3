
#include <iostream>

void array_shift_on_one(int* begin, int* end)
{
    int size = end - begin;

    int temp = *(end - 1);

    for (int i = size - 2; i >= 0; i--)
    {
        *(begin + i + 1) = *(begin + i);
    }
    *begin = temp;
    
}

void array_shift(int* begin, int* end, int shift)
{
    for (int i = 0; i < shift; i++)
    {
        array_shift_on_one(begin, end);
    }
}

int main()
{
    int* array = new int[5];

    for (int i = 0; i < 5; i++)
    {
        std::cin >> array[i];
    }

    array_shift(array, array + 5, 2);

    for (int i = 0; i < 5; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
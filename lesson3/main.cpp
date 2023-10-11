
#include <iostream>

template<typename T>
T add(const T left, const T right)
{
    return left + right;
}

struct Complex
{
    friend std::ostream& operator<<(std::ostream&, const Complex&);
    friend Complex operator-(const Complex&, const Complex&);
    friend Complex operator*(const Complex&, const Complex&);
    friend Complex operator+(const Complex&, const Complex&);
    friend Complex operator/(const Complex&, const Complex&);

    Complex(double real, double image) : real(real), image(image) {}

    double real;
    double image;
};

std::ostream& operator<<(std::ostream& out, const Complex& num)
{
    out << "( " << num.real << " + " << num.image << "*i" << " )";
}

Complex operator+(const Complex& left, const Complex& right)
{
    return Complex(left.real + right.real, left.image + right.image);
}

Complex operator-(const Complex& left, const Complex& right)
{
    return Complex(left.real - right.real, left.image - right.image);
}

Complex operator*(const Complex& left, const Complex& right)
{
    return Complex(left.real * right.real - left.image * right.image, left.real * right.image + left.image * right.real);
}

Complex operator/(const Complex& left, const Complex& right)
{
    //return Complex(left.real / right.real, left.image / right.image);
}

int main()
{
    std::cout << add(1.1, 1.1) << std::endl;
    std::cout << add(5u, 5u) << std::endl;
    std::cout << add(std::string("Hello "), std::string(" world")) << std::endl;

    Complex c1(1, 1);
    Complex c2(1, -1);
    
    std::cout << c1 << " + " << c2 << " = " << c1 + c2 << std::endl;
    std::cout << c1 << " * " << c2 << " = " << c1 * c2 << std::endl;
    std::cout << c1 << " - " << c2 << " = " << c1 - c2 << std::endl;
    std::cout << c1 << " / " << c2 << " = " << c1 / c2 << std::endl;

    return 0;
}

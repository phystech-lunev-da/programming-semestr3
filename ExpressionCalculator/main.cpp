
#include <cstdlib>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <variant>

double solve_postfix(std::string s_expr)
{
    auto my_isspace = [](char c) {return std::isspace(c);};
    auto erased = std::remove_if(s_expr.begin(), s_expr.end(), my_isspace);
    s_expr.erase(erased, s_expr.end());

    std::vector<std::variant<double, std::string>> expr;

    std::string s_num;
    std::string digits("1234567890");

    for (std::string::iterator iter = s_expr.begin(); iter != s_expr.end(); iter++)
    {
        if (digits.find(*iter) != -1)
        {
            s_num.append(std::string(*iter));
        }
    }
}

int main()
{
    
}
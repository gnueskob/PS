// https://www.acmicpc.net/problem/4949
#include "_fileRead.hpp"
GNUES::FileRead f("4949.txt");

#include <iostream>
#include <stack>
#include <map>
int main()
{
    std::string str;
    std::map<char, char> pair_char;
    pair_char.emplace(')', '(');
    pair_char.emplace(']', '[');

    while (std::getline(std::cin, str))
    {
        if (str.empty() == false && str.at(0) == '.')
            break;

        std::stack<char> parentheses;
        bool valid = true;
        for (const auto& c : str)
        {
            if (c == '(' || c == '[')
            {
                parentheses.push(c);
            }
            else if (c == ')' || c == ']')
            {
                if (parentheses.empty() || parentheses.top() != pair_char[c])
                {
                    valid = false;
                    break;
                }
                parentheses.pop();
                continue;
            }
        }

        if (parentheses.empty() == false)
            valid = false;

        std::cout << (valid ? "yes" : "no") << '\n';
    }
}
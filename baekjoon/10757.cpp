// 큰 수 A+B
// https://www.acmicpc.net/problem/10757
#include <iostream>
int main()
{
    std::string a, b;
    std::cin >> a >> b;
    if (a.length() < b.length())
        a.swap(b);
    int carry = 0;

    size_t a_len = a.length(), b_len = b.length();

    std::string out;

    auto atoi = [](const char& c) -> int { return c - '0'; };
    auto itoa = [](const int& i) -> char { return i + '0'; };

    while (b_len--)
    {
        --a_len;
        int num1 = atoi(a.at(a_len));
        int num2 = atoi(b.at(b_len));
        int sum = num1 + num2 + carry;
        carry = sum / 10;
        int remainder = sum % 10;
        char c = itoa(remainder);
        out = c + out;
    }

    while (a_len--)
    {
        int num = atoi(a.at(a_len));
        int sum = carry + num;
        carry = sum / 10;
        int remainder = sum % 10;
        char c = itoa(remainder);
        out = c + out;
    }

    if (carry > 0)
    {
        char c = itoa(carry);
        out = c + out;
    }

    std::cout << out;
}
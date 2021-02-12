// 손익분기점
// https://www.acmicpc.net/problem/1712
#include <iostream>
int main()
{
    int fixed_cost = 0;
    int variable_cost = 0;
    int price = 0;
    std::cin >> fixed_cost >> variable_cost >> price;

    // fixed_cost + variable_cost * N < price * N
    // N > fixed_cost / (price - variable_cost)
    int break_even_point = 0;
    if ((price - variable_cost) <= 0)
        break_even_point = -1;
    else
        break_even_point = fixed_cost / (price - variable_cost) + 1;    // floor
    std::cout << break_even_point;
}
// https://www.acmicpc.net/problem/18258
#include "_fileRead.hpp"
GNUES::FileRead f("18258.txt");

/* stl 사용
#include <iostream>
#include <queue>
int main()
{
    int n;
    std::cin >> n;
    std::queue<int> q;
    while (n--)
    {
        std::string op;
        std::cin >> op;
        if (op == "push")
        {
            int num;
            std::cin >> num;
            q.emplace(num);
        }
        else if (op == "pop")
        {
            if (q.empty())
            {
                std::cout << "-1\n";
                continue;
            }
            std::cout << q.front() << '\n';
            q.pop();
        }
        else if (op == "size")
        {
            std::cout << q.size() << '\n';
        }
        else if (op == "empty")
        {
            std::cout << q.empty() << '\n';
        }
        else if (op == "front")
        {
            if (q.empty())
            {
                std::cout << "-1\n";
                continue;
            }
            std::cout << q.front() << '\n';
        }
        else if (op == "back")
        {
            if (q.empty())
            {
                std::cout << "-1\n";
                continue;
            }
            std::cout << q.back() << '\n';

        }
    }
}
*/

// 직접 구현
#include <iostream>
#include <vector>
int main()
{
    std::vector<int> q(2'000'000, 0);
    int back_idx = 0;
    int front_idx = 0;

    int n;
    std::cin >> n;
    while (n--)
    {
        std::string op;
        std::cin >> op;
        if (op == "push")
        {
            int num;
            std::cin >> num;
            q[back_idx++] = num;
        }
        else if (op == "pop")
        {
            if ((back_idx - front_idx) == 0)
            {
                std::cout << "-1\n";
                continue;
            }
            std::cout << q[front_idx++] << '\n';
        }
        else if (op == "size")
        {
            std::cout << (back_idx - front_idx) << '\n';
        }
        else if (op == "empty")
        {
            std::cout << ((back_idx - front_idx) == 0) << '\n';
        }
        else if (op == "front")
        {
            if ((back_idx - front_idx) == 0)
            {
                std::cout << "-1\n";
                continue;
            }
            std::cout << q[front_idx] << '\n';
        }
        else if (op == "back")
        {
            if ((back_idx - front_idx) == 0)
            {
                std::cout << "-1\n";
                continue;
            }
            std::cout << q[back_idx-1] << '\n';
        }
    }
}
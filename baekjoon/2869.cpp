// 달팽이는 올라가고 싶다
// https://www.acmicpc.net/problem/2869
#include <iostream>
int main()
{
    int height, up, down;
    std::cin >> up >> down >> height;
    // height <= (up - down) * (day - 1) + up
    // day >= (height - up) / (up - down) + 1
    // day = ceil((height - up) / (up - down)) + 1
    // day = floor((height - up + (up - down - 1))) / (up - down)) + 1
    std::cout << (height - down - 1) / (up - down) + 1; // int divide automatic floor
}
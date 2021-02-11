// A+B - 4
// https://www.acmicpc.net/problem/10951
#include <iostream>
#include <fstream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL); std::cout.tie(NULL);

  std::ifstream file("./baekjoon/input/10951.txt");
  if (file.is_open() == false)
    return 0;

  std::cin.rdbuf(file.rdbuf()); // swap

  int a,b;
  while (std::cin >> a >> b)
  {
    std::cout << a+b << '\n';
  }

  return 0;
}

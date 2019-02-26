// 상수
// https://www.acmicpc.net/problem/2908
#include<iostream>
#include<string>
using namespace std;

inline void printNum(string& num) { for(int i=2; i>=0; i--) cout << num.at(i); }

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  string num1, num2;
  cin >> num1 >> num2;
  const int len = 3;
  for(int i=len-1; i>=0; i--) {
    if(num1.at(i) > num2.at(i)) { printNum(num1); break; }
    else if(num1.at(i) < num2.at(i)) { printNum(num2); break; }
  }
  return 0;
}
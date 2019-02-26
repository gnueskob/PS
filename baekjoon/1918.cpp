// 후위표기식
// https://www.acmicpc.net/problem/1918
#include<iostream>
#include<string>
using namespace std;

#define STACK_SIZE 100

char stack[STACK_SIZE] = {0, };
#define top() stack[idx]
#define push(c) stack[++idx] = c
#define pop() --idx

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("./input/1918.txt", "r", stdin);

  char c;
  int idx = -1, cnt = 0;
  while((c = cin.get()) >= 0 && c < 128 && c != cin.eof() && c != '\n') {
    switch(c) {
      default: cout << c; break;
      case '(': push(c); break;
      case ')': while(idx >= 0 && top() != '(') { cout << top(); pop(); } pop(); break;
      case '+':
      case '-': while(idx >= 0 && top() != '(') { cout << top(); pop(); } push(c); break;
      case '*':
      case '/': while(idx >= 0 && (top() == '*' || top() == '/')) { cout << top(); pop(); } push(c); break;
    }
  }

  while(idx >= 0) { cout << top(); pop(); }
  return 0;
}
// 숫자의 개수
// https://www.acmicpc.net/problem/2577
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // freopen("./input/2577.txt", "r", stdin);

  int a, b, c, num[10]={0,}, mul;
  cin >> a >> b >> c;
  mul = a*b*c;
  do {
    num[mul%10]++;
    mul/=10;
  } while(mul);
  for(int i=0; i<10; i++) cout << num[i] << '\n';
  return 0;
}
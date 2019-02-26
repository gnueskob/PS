// 평균 점수
// https://www.acmicpc.net/problem/10039
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int num, aver = 0;
  for(int i=0; i<5; i++) {
    cin >> num;
    if(num>40) aver += num/5;
    else aver += 8;
  }
  cout << aver;
  return 0;
}
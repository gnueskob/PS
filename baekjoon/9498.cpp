// 시험 성적
// https://www.acmicpc.net/problem/9498
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // freopen("./input/9498.txt", "r", stdin);
  int N; cin >> N;
  if(N>=90) { cout << 'A'; }
  else if(N>=80) { cout << 'B'; }
  else if(N>=70) { cout << 'C'; }
  else if(N>=60) { cout << 'D'; }
  else { cout << 'F'; }
  return 0;
}
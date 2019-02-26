// 평균은 넘겠지
// https://www.acmicpc.net/problem/4344
#include<iostream>
using namespace std;
const int MAX = 1000;
int score[MAX];

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  freopen("./input/4344.txt", "r", stdin);
  int C, N; double aver, num;
  cin >> C;
  while(C--) {
    aver = 0, num = 0;
    cin >> N;
    for(int i=0; i<N; i++) {
      cin >> score[i];
      aver += score[i];
    }
    aver /= N;
    for(int i=0; i<N; i++) if(score[i]>aver) num++;
    cout.setf(ios::fixed); cout.precision(3);
    cout << num/N*100 << "%\n";
  }
  return 0;
}
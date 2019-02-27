// 윷놀이
// https://www.acmicpc.net/problem/2490
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int v, front = 0;
  char yut[5] = {'E', 'A', 'B', 'C', 'D'};
  for(int i=0; i<3; i++) {
    for(int j=0; j<4; j++) { cin >> v; if(!v) front++; }
    cout << yut[front] << '\n';
    front = 0;
  }
  return 0;
}
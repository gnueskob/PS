// 숫자의 합
// https://www.acmicpc.net/problem/11720
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // freopen("./input/11720.txt", "r", stdin);
  int n, ans=0; char c;
  cin >> n;
  for(int i=0; i<n; i++) { cin >> c; ans += c - '0'; }
  cout << ans;
  return 0;
}
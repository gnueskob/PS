// N과 M
// https://www.acmicpc.net/problem/15649
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'

int N, M;
int arr[8] = {1,2,3,4,5,6,7,8};
int fact[8] = {1, 1, 2, 6, 24, 120, 720, 5040};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  freopen("./input/15649.txt", "r", stdin);
  cin >> N >> M;
  int mod = N - M, idx = 1;
  do {
    if (idx % fact[mod] == 0) {
      for (size_t i=0; i<M; i++) {
        cout << arr[i] << ' ';
      }
      cout << endl;
    }
    idx++;
  } while(next_permutation(arr, arr + N));
  return 0;
}
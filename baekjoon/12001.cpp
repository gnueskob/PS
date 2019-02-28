#include<iostream>
#include<tuple>
using namespace std;

int n, b, ans;
typedef tuple<int, int> t2;
t2 *cowPos;

int max(const int* cowNum, int size);

int main() {
  freopen("./input/12001.txt", "r", stdin);

  cin >> n >> b;
  ans = n;
  cowPos = new t2[n];
  for(int i=0; i<n; i++)
    cin >> get<0>(cowPos[i]) >> get<1>(cowPos[i]);

  for(int i=0; i<n; i ++) {
    for(int j=0; j<n; j ++) {
      int cowNum[4] = {0, };
      for(int k=0; k<n; k++) {
        int x, y, axisX, axisY;
        tie(x, y) = cowPos[k];
        tie(axisX, ignore) = cowPos[i];
        tie(ignore, axisY) = cowPos[j];
        if (x < axisX + 1 && y < axisY + 1) cowNum[0]++;
        else if (x < axisX + 1 && y > axisY + 1) cowNum[1]++;
        else if (x > axisX + 1 && y < axisY + 1) cowNum[2]++;
        else cowNum[3]++;
      }
      int maxCowNum = max(cowNum, 4);
      ans = ans > maxCowNum ? maxCowNum : ans;
    }
  }

  cout << ans;
  return 0;
}

int max(const int* cowNum, int size) {
  int maxCowNum = 0;
  for(int i=0; i<size; i++)
    maxCowNum = maxCowNum < cowNum[i] ? cowNum[i] : maxCowNum;
  return maxCowNum;
}
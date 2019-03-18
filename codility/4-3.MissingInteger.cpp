#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int solution(vector<int> &A);
int main() {
  vector<int> A = {1, 3, 6, 4};
  cout << solution(A);
  return 0;
}

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int solution(vector<int> &A) {
  // write your code in C++14 (g++ 6.2.0)
  int size = A.size();
  sort(A.begin(), A.end());
  int min = 1;
  for(int i=0; i<size; i++)
    if(A[i] < 0) continue;
    else if (A[i] == min) { min++; }
    else if (min < A[i]) return min;
  return min;
}
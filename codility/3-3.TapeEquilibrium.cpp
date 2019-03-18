#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int solution(vector<int> &A);
int main() {
  vector<int> A = {3, 1, 2, 4, 3};
  cout << solution(A);
  return 0;
}

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int solution(vector<int> &A) {
  // write your code in C++14 (g++ 6.2.0)
  int size = A.size(), min = 2e8;
  for(int i=1; i<size; i++) A[i] += A[i-1];
  for(int i=1; i<size; i++) {
    int diff = abs(A[i-1] - (A[size-1] - A[i-1]));
    min = min > diff ? diff : min;
  }
  return min;
}
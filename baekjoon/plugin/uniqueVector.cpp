#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
  vector<int> li(10,1);
  li[3] = 2;
  li[6] = 6;
  li[7] = 11;

  /**
   * vector에서 unique한 값들을 남기고 전부 지우려 하는 경우
   * unique 함수는 해당 리스트의 앞부분 부터 unique한 값들로 덮어씌운후
   * 'unique한 값으로 이루어진 리스트'의 '마지막 원소 다음칸'의 주소를 리턴
   *
   * 따라서 vector stl에 unique를 사용할 경우 앞 부분 부터 unique한 값들로 채워지지만
   * 여전히 뒤쪽에 이전 vector에서 사용했던 값들이 남아있는 상태
   *
   * unique 함수의 리턴 값이 unique한 vector의 end 이므로
   * erase를 이용해서 깔끔하게 정리할 수 있음.
   *
   * 단, unique 함수 사용 이전에 해당 리스트는 '정렬'되어있어야함
   */
  sort(li.begin(), li.end());
  li.erase(unique(li.begin(), li.end()), li.end());

  for(auto it : li) cout << it << ' ';
  return 0;
}
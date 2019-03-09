#include<bits/stdc++.h>
using namespace std;

/**
 * 도움이 되는 각종 비트 연산 모음
 */

/**
 * 가장 가까운 2^x 찾기
 * Only 정수 타입 (unsigned) short, int, long long etc..
 * 가장 최상위 비트(MSB) 이하로 모든 비트를 1로 set 시킨 후 1을 더하는 방식
 */
template <typename T>
T getCeilPowerOfTwo(T v) {
  v--;
  for(int i=1; i<sizeof(T)*8; i<<=1) v |= v >> i;
  return ++v;
}

/**
 * 2의 거듭제곱 꼴인지 판단하기
 * 2의 거듭제곱 꼴이면, 비트가 오직 하나만 set 되어있음
 * 2's complement의 수와 & 연산시 자기 자신
 * ex)
 *  32:   0010 0000(2)
 * ~32:   1101 1111(2) (one's complement)
 * -32:   1110 0000(2) (two's complement)
 *
 *     32:   0010 0000(2)     17:   0001 0001(2)
 *  & -32:   1110 0000(2)  & -17:   1110 1111(2)
 *  =  32:   0010 0000(2)  =   1:   0000 0001(2)
 *
 * OR
 * 1을 뺀 수와 & 연산시 0이 되면, 비트가 하나만 set 되었다는 것을 알 수 있음
 */
template <typename T>
bool isPowerOfTwo(T v) { return (v & -v) == v; }
// bool isPowerOfTwo(T v) { return !(v & (v-1); }

// set된 비트 중 가장 높은 비트
// ex) v = 0011 0100(2), return: 0010 0100(2)
template <typename T>
T getHighestBit(T v) { for(int i=1; i<sizeof(v); i<<=1) v|= v >> i; return ++v >> 1;}

// set된 비트 중 가장 낮은 비트
// ex) v = 1011 0100(2), return: 0000 0100(2)
template <typename T>
T getLowestBit(T v) { return v & -v; }

// 가장 높은 비트 앞으로 set된 mask
// ex) v = 0001 0010(2), return: 1111 0000(2)
template <typename T>
T getUpperHighestBitMask(T v) {
  for(int i=1; i<sizeof(v); i<<=1) v|= v >> i; ++v >>= 1;
  return ~(v-1);
}

// 가장 낮은 비트이하로 set된 mask
// ex) v = 1010 0000(2), return: 0011 1111(2)
template <typename T>
T getUnderLowestBitMask(T v) { return v ^ (v-1); }

// 가장 높은 비트를 unset
// ex) v = 1101 0100(2), return: 0101 0100(2)
template <typename T>
T getBitsOfUnsettedHgihestBit(T v) {
  T t = v; for(int i=1; i<sizeof(v); i<<=1) v|= v >> i; ++v >>= 1;
  return t ^ v;
}

// 가장 낮은 비트를 unset
// ex) v = 1101 0100(2), return: 1101 0000(2)
template <typename T>
T getBitsOfUnsettedLowestBit(T v) { return v & (v - 1); }

// set된 비트의 개수
// ex) v = 1101 0100(2), return: 4
template <typename T>
int getCountSettedBits(T v) { int cnt=0; while(v) v &= v-1, cnt++; return cnt; }

int main() {
  cout << getCeilPowerOfTwo((int) 256) << '\n'; // output : 256
  cout << getCeilPowerOfTwo((int) 789) << '\n'; // output : 1024

  cout << boolalpha << isPowerOfTwo(1024) << '\n';  // output : true
  cout << boolalpha << isPowerOfTwo(777) << '\n';   // output : false

  cout << bitset<8>(getHighestBit((int) 0b0010'1010)) << '\n';  // output: 0b 0010'0000
  cout << bitset<8>(getLowestBit((int) 0b0010'1010)) << '\n';   // output: 0b 0000'0010

  cout << bitset<8>(getUpperHighestBitMask((int) 0b0010'1000)) << '\n'; // output: 0b 1110'0000
  cout << bitset<8>(getUnderLowestBitMask((int) 0b0010'1000)) << '\n';  // output: 0b 0000'1111

  cout << bitset<8>(getBitsOfUnsettedHgihestBit((int) 0b1101'0100)) << '\n';  // output: 0b 0101'0100
  cout << bitset<8>(getBitsOfUnsettedLowestBit((int) 0b1101'0100)) << '\n';   // output: 0b 1101'0000

  cout << getCountSettedBits((int) 0b1101'0100) << '\n';  // output: 4
  return 0;
}
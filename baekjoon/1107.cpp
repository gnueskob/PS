// 리모컨
// https://www.acmicpc.net/problem/1107
#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define min(a,b) (a<b?a:b)

int main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int N, M, b, bmin=0, bmax=9, bcnt=0, chanel=100; cin >> N >> M;
  bool broken[10]{};
  while(M--) { cin >> b; broken[b] = true; bcnt++; }

  if(bcnt == 10) { cout << abs(chanel-N); return 0; }

  while(bmin<=9 && broken[bmin]) bmin++;
  while(bmax>=0 && broken[bmax]) bmax--;

  int min[7]{}, max[7]{}, bidx;
  int minNum=0, maxNum=0;
  string nstr = to_string(N);
  // First broken number index in N
  for(bidx=0; bidx<nstr.length(); bidx++) if(broken[nstr.at(bidx) - '0']) break;

  if(bidx != nstr.length()) { // There exists broken number in N at least one
    int i, prefix, nprefix;
    bool carry;
    // Set the numbers to default after first broken number
    for(i=0; i<nstr.length()-bidx-1; i++) max[6-i] = bmin, min[6-i] = bmax;

    // find maxNum
    prefix = 6-i; nprefix = bidx; carry = false;
    while(nprefix>=0 || carry) {
      int num = nprefix >=0 ? nstr.at(nprefix) - '0' : 0;
      if(carry) num++;
      while(1) {
        if(num<=9 && broken[num]) num++;
        else {
          if(num>9) { max[prefix--] = bmin; carry = nprefix >=0 ? true : false; }
          else { max[prefix--] = num; carry = false; }
          nprefix--; break;
        }
      }
    }
    for(int i=0; i<7; i++) maxNum = maxNum*10 + max[i];

    // find minNum
    prefix = 6-i; nprefix = bidx; carry = false;
    while(nprefix>=0) {
      int num = nstr.at(nprefix) - '0';
      if(carry) num--;
      while(1) {
        if(num>=0 && broken[num]) num--;
        else {
          if(num<0) { min[prefix] = nprefix==0 ? (prefix==6 ? -1 : 0) : bmax; carry = true; prefix--; }
          else { min[prefix--] = num; carry = false; }
          nprefix--; break;
        }
      }
    }
    for(int i=0; i<7; i++) minNum = minNum*10 + min[i];

  } else { // No broken number in N
    minNum = maxNum = N;
  }
  int diff = abs(chanel - N);
  int minLen = 0, maxLen = 0, t;
  t=minNum; while(t) minLen++, t/=10; if(!minNum) minLen=1;
  t=maxNum; while(t) maxLen++, t/=10;
  if(!maxNum) maxNum = 1e9;
  if(minNum==-1) minNum = -1e9;
  cout << min(diff, min(N-minNum+minLen, maxNum-N+maxLen));
  return 0;
}
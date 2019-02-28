// 최대공약수
// https://www.acmicpc.net/problem/1850
#include<iostream>
#include<cstring>
using namespace std;

static const int wbuf_size = 1 << 18;
static int write_pos = 0;
static char write_buf[wbuf_size];

typedef long long ll;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll a, b, c;
  cin >> a >> b;
  while(b) { c=a%b; a=b; b=c; }
  while (a >= 0) {
    write_pos = a >= wbuf_size ? wbuf_size : a;
    memset(write_buf, '1', write_pos);
    fwrite(write_buf, 1, write_pos, stdout);
    a -= wbuf_size;
  }
  return 0;
}
// CPU
// https://www.acmicpc.net/problem/16506
#include<iostream>
#include<string>
#include<bitset>
using namespace std;

string opcode;

bool findOpcode(const char *);

int main() {
  freopen("./input/16506.txt", "r", stdin);

  int n;
  cin >> n;
  if (cin.eof()) return 0;

  for(int i=0; i<n; i++) {
    cin >> opcode;
    int r1, r2, r3;
    cin >> r1 >> r2 >> r3;

    bool hasC = opcode.at(opcode.size() - 1) == 'C';
    if (findOpcode("ADD")) {
      cout << "0000";
    } else if (findOpcode("SUB")) {
      cout << "0001";
    } else if (findOpcode("MOV")) {
      cout << "0010";
    } else if (findOpcode("AND")) {
      cout << "0011";
    } else if (findOpcode("OR")) {
      cout << "0100";
    } else if (findOpcode("NOT")) {
      cout << "0101";
    } else if (findOpcode("MULT")) {
      cout << "0110";
    } else if (findOpcode("LSFTL")) {
      cout << "0111";
    } else if (findOpcode("LSFTR")) {
      cout << "1000";
    } else if (findOpcode("ASFTR")) {
      cout << "1001";
    } else if (findOpcode("RL")) {
      cout << "1010";
    } else if (findOpcode("RR")) {
      cout << "1011";
    } else {
      cout << "wrong";
    }

    cout << hasC ? '1' : '0';
    cout << '0';
    cout << bitset<3>(r1);
    cout << bitset<3>(r2);
    if (hasC) {
      cout << bitset<4>(r3);
    } else {
      cout << bitset<3>(r3);
      cout << '0';
    }
    cout << endl;
    opcode.clear();
  }

  return 0;
}

bool findOpcode(const char *str) {
  return opcode.find(str) != std::string::npos;
}
// 중국 신분증 번호
// https://www.acmicpc.net/problem/16196
#include <iostream>
#include <string>
using namespace std;

bool isValidDate(int year, int month, int day);

int main() {
  freopen("./input/16196.txt", "r", stdin);

  string id;
  cin >> id;
  if (cin.eof()) return 0;

  if (id.size() != 18) {
    cout << "I\n";
    return 0;
  }

  int regionCode = atoi(id.substr(0, 6).c_str());
  // cout << "RegionCode : " << regionCode << endl;
  int n;
  bool isVaild = false;
  cin >> n;
  for (int i=0; i<n; i++) {
    int chkRegionCode;
    cin >> chkRegionCode;
    // cout << "cmp : " << chkRegionCode << endl;
    if (regionCode == chkRegionCode) {
      // cout << "Valid!" << endl;
      isVaild = true;
      break;
    }
  }
  if (!isVaild) {
    cout << "I\n";
    return 0;
  }
  // cout << "[PASS] : region code" << endl;

  int birthdayCode = atoi(id.substr(6, 8).c_str());
  int year = birthdayCode / 10000;
  int month = (birthdayCode - year * 10000) / 100;
  int day = birthdayCode % 100;
  // cout << "bdayCode : " << year << '_' << month << '_' << day << endl;
  if (!isValidDate(year, month, day)) {
    cout << "I\n";
    return 0;
  }
  // cout << "[PASS] : birthday code" << endl;

  int codeSum = 0;
  // cout << id << endl;
  for (int i=0; i<17; i++) {
    // cout << id.at(i);
    codeSum += ((id.at(i) - '0') << (17 - i));
  }
  // cout << endl << codeSum << endl;

  // checkSum ver.1
  // int x = 1 - (codeSum % 11);
  // if (x < 0) x += 11;

  // char checkSum;
  // if (x == 10) checkSum = 'X';
  // else checkSum = x + '0';
  // // cout << "checkSum : " << checkSum << endl;
  // if (checkSum == id.at(17)) {
  //   cout << "I";
  //   return 0;
  // }

  // checkSum ver.2
  int x = id.at(17) == 'X' ? 10 : id.at(17) - '0';
  int checkSum = (codeSum + x) % 11;
  if (checkSum != 1) {
    cout << "I\n";
    return 0;
  }
  // cout << "[PASS] : checkSum code" << endl;

  int sexCode = atoi(id.substr(14,3).c_str());
  // cout << "SexCode : " << sexCode << endl;
  if (!sexCode) {
    cout << "I\n";
    return 0;
  }
  // cout << "[PASS] : sex code" << endl;

  bool isMale = sexCode % 2;
  if (isMale) cout << "M\n";
  else cout << "F\n";

  return 0;
}

bool isValidDate(int year, int month, int day) {
  int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (year < 1900 || year > 2011) return false;
  if (month < 1 || month > 12) return false;
  if (day < 1) return false;

  if ((year % 4 == 0) - (year % 100 == 0) + (year % 400 == 0)) days[2] = 29;

  if (day > days[month]) return false;

  return true;
}
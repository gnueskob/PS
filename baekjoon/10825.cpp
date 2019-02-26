// 국영수
// https://www.acmicpc.net/problem/10825
#include<iostream>
#include<string>
#include<set>
using namespace std;

#define endl '\n';

class Student {
  public:
    string name;
    int lang, eng, math;
    Student() {};
    Student(string n, int l, int e, int m) : name(n), lang(l), math(m) {};
    string getName() { return name; };
    bool operator < (const Student &stu) const {
      if (lang != stu.lang) return lang > stu.lang;
      if (eng != stu.eng) return eng < stu.eng;
      if (math != stu.math) return math > stu.math;
      return name < stu.name;
    }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("./input/10825.txt", "r", stdin);

  int n;
  Student stu;
  set<Student> students;

  cin >> n;
  for(size_t i=0; i<n; i++) {
    cin >> stu.name >> stu.lang >> stu.eng >> stu.math;
    students.insert(stu);
  }

  for(auto it : students) {
    cout << it.name << endl;
  }

  return 0;
}

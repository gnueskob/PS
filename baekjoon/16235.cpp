// 나무 재테크
// https://www.acmicpc.net/problem/16235
#include<iostream>
#include<deque>
#include<vector>
#include<map>
#include<algorithm>

#define getKey(r, c) (r * 1000 + c);
using namespace std;

typedef pair<int, bool> ib;
typedef deque<ib> dq;
typedef enum {SPRING, SUMMER, FALL} season;

int n, m, k, ans;
int grid[11][11];
int nutrient[11][11];
dq trees[11][11];
map<int, dq*> treeMap;
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

void simulation();
void plant(int r, int c, int age);
void displayTreeMap();
void displayGrid();
void displayNut();

int main() {
  freopen("./input/16235.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ans = 0;
  fill(&grid[0][0], &grid[10][11], 5);
  cin >> n >> m >> k;
  for(int i=1; i<=n; ++i)
    for(int j=1; j<=n; j++)
      cin >> nutrient[i][j];

  for(int i=0; i<m; i++) {
    int r, c, age;
    cin >> r >> c >> age;
    plant(r, c, age);
  }

  // displayNut();
  // cout << "[start] sumulation" << endl;

  simulation();

  cout << ans;
  return 0;
}

void plant(const int r, const int c, const int age) {
  int key = getKey(r, c);
  auto it = treeMap.insert({ key, nullptr });
  // TreeMap dq* = it.first->second
  // Insert Success Flag = it.second;
  if (it.second) {
    trees[r][c].push_front({ age, false });
    it.first->second = &trees[r][c];
  } else {
    it.first->second->push_front({ age, false });
  }
  ans++;
}

void forEachTreeMap(season _season) {
  for(auto it = treeMap.begin(); it != treeMap.end(); it++) {
    int r = it->first / 1000, c = it->first % 1000;
    auto dqTree = it->second;
    if (dqTree == nullptr) continue;
    switch(_season) {
      default: break;
      case SPRING:
        for (auto dqit = dqTree->begin(); dqit != dqTree->end(); dqit++) {
          int age = dqit->first;
          if (grid[r][c] < age) dqit->second = true;
          else { grid[r][c] -= age; dqit->first++; }
        }
        break;
      case SUMMER:
        for (int i = dqTree->size()-1; i >=0; i--) {
          int age; bool isDead;
          tie(age, isDead) = (*dqTree)[i];
          if (isDead) { dqTree->pop_back(); grid[r][c] += age/2; ans--; }
        }
        break;
      case FALL:
        for (auto dqit = dqTree->begin(); dqit != dqTree->end(); dqit++) {
          int age = dqit->first;
          if (age%5) continue;
          else {
            for (int j=0; j<8; j++) {
              int newR = r + dy[j], newC = c + dx[j];
              if (1 <= newR && newR <= n && 1 <= newC && newC <= n)
                plant(newR, newC, 1);
            }
          }
        }
        break;
    }
  }
}

void simulation() {
  // displayGrid();
  // displayTreeMap();
  for(int year=0; year<k; year++) {
    // cout << "Year : " << year + 1 << endl;
    forEachTreeMap(SPRING);
    // cout << "[SPRING]*********************" << endl;
    // displayGrid();
    // displayTreeMap();
    forEachTreeMap(SUMMER);
    // cout << "[SUMMER]*********************" << endl;
    // displayGrid();
    // displayTreeMap();
    forEachTreeMap(FALL);
    // cout << "[FALL]*********************" << endl;
    // displayGrid();
    // displayTreeMap();

    // WINTER
    for(int i=1; i<=n; i++)
      for(int j=0; j<=n; j++)
        grid[i][j] += nutrient[i][j];
    // cout << "[WINTER]*********************" << endl;
    // displayGrid();
    // displayTreeMap();

    if (ans <= 0) break;
  }
}

void displayGrid() {
  cout << "---------GRID--------" << endl;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++)
      cout << grid[i][j] << ' ';
    cout << endl;
  }
}

void displayNut() {
  cout << "---------NUT---------" << endl;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++)
      cout << nutrient[i][j] << ' ';
    cout << endl;
  }
}

void displayTreeMap() {
  cout << "---------TREE--------" << endl;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      if (!trees[i][j].empty()) cout << trees[i][j].size() << ' ';
      else cout << "- ";
    }
    cout << endl;
  }
}
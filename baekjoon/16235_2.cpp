// 나무 재테크
// https://www.acmicpc.net/problem/16235
#include<iostream>
#include<deque>

using namespace std;

typedef pair<int, bool> ib;
typedef deque<ib> dq;
typedef enum {SPRING, SUMMER, FALL} season;

int n, m, k, ans;
int grid[10][10];
int nutrient[10][10];
dq trees[10][10];
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

void simulation();

int main() {
  freopen("./input/16235.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ans = 0;
  cin >> n >> m >> k;
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++) {
      cin >> nutrient[i][j];
      grid[i][j] = 5;
    }

  for(int i=0; i<m; i++) {
    int r, c, age;
    cin >> r >> c >> age;
    trees[r-1][c-1].push_front({ age, false });
    ans++;
  }

  for(int year=0; year<k; year++) {
    for(int r=0; r<n; r++) for(int c=0; c<n; c++) {
      if (trees[r][c].empty()) continue;
      int nut = 0;
      for (int i=0; i<trees[r][c].size(); i++) {
        int age = trees[r][c][i].first;
        if (grid[r][c] < age) {
          nut += age/2;
          trees[r][c][i].second = true;
          ans--;
        } else { grid[r][c] -= age; trees[r][c][i].first++; }
      }
      grid[r][c] += nut;
      for(int i=trees[r][c].size()-1; i>=0; i--) {
        if (trees[r][c][i].second) trees[r][c].pop_back();
        else break;
      }
    }

    for(int r=0; r<n; r++) for(int c=0; c<n; c++) {
      if (trees[r][c].empty()) continue;
      int nut = 0;
      for (int i=0; i<trees[r][c].size(); i++) {
        int age = trees[r][c][i].first;
        if (age%5) continue;
        else {
          for (int j=0; j<8; j++) {
            int newR = r + dy[j], newC = c + dx[j];
            if (0 <= newR && newR < n && 0 <= newC && newC < n) {
              trees[newR][newC].push_front({ 1, false });
              ans++;
            }
          }
        }
      }
    }

    // WINTER
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        grid[i][j] += nutrient[i][j];

    if (ans <= 0) break;
  }

  cout << ans;
  return 0;
}

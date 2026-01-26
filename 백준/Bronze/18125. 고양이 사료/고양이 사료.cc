// 18125. 고양이 사료
#include<iostream>
using namespace std;

int petFood[105][105];

bool isSame(int r, int c) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      int tmp;
      cin >> tmp;
      if (petFood[i][j] != tmp) {
        return 0;
      }
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int r, c;
  cin >> r >> c;

  for (int i = 0; i < c; i++) {
    for (int j = 0; j < r; j++) {
      cin >> petFood[j][c - i - 1];
    }
  }

  if (isSame(r, c)) {
    cout << R"border(|>___/|        /}
| O < |       / }
(==0==)------/ }
| ^  _____    |
|_|_/     ||__|)border";
  }
  else {
    cout << R"border(|>___/|     /}
| O O |    / }
( =0= )""""  \
| ^  ____    |
|_|_/    ||__|)border";
  }
}
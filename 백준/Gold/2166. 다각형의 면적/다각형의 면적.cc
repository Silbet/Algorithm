// 2166. 다각형의 면적
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  long long x1, y1, x2, y2, x, y;
  cin >> x2 >> y2;
  x = x2;
  y = y2;

  long long result = 0;
  for (int i = 0; i < n - 1; i++) {
    x1 = x2;
    y1 = y2;
    cin >> x2 >> y2;

    result += (x1 * y2 - x2 * y1);
  }
  result += (x2 * y - x * y2);

  double width = abs(result) * 0.5;

  printf("%.1lf", width);
}
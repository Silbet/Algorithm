// 1010. 다리놓기
#include<iostream>
#include<cmath>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int t;
  cin >> t;

  while (t--) {
    int n, entire_site;
    cin >> n >> entire_site;

    int selected_site = min(n, entire_site - n);

    int result = 1;
    for (int i = 1; i <= selected_site; i++) {
      result = result * (entire_site - i + 1) / i;
    }

    cout << result << "\n";

  }
}
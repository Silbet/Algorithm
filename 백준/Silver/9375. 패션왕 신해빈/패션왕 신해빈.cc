// 9375. 패션왕 신해빈
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    unordered_map<string, int> wearable;
    vector<string> item_type;
    for (int i = 0; i < n; i++) {
      string item, type;
      cin >> item >> type;

      if (wearable.count(type)) {
        wearable[type]++;
      }
      else {
        wearable[type] = 1;
        item_type.push_back(type);
      }
    }

    int result = 1;
    for (int i = 0; i < item_type.size(); i++) {
      result *= (wearable[item_type[i]] + 1);
    }
    cout << result - 1 << "\n";
  }
}
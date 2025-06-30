// 1927. 최소 힙
#include<iostream>
#include<queue>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  priority_queue<int, vector<int>, greater<int>> min_heap;

  int n;
  cin >> n;
  
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;

    if (num == 0) {

      if (min_heap.empty()) cout << '0';
      else {
        cout << min_heap.top();
        min_heap.pop();
      }
      cout << "\n";
    }

    else {
      min_heap.push(num);
    }

  }
}
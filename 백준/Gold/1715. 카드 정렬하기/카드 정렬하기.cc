// 1715. 카드 정렬하기
#include<iostream>
#include<queue>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
 
  int n;
  cin >> n;

  priority_queue<int, vector<int>, greater<int>> min_heap;

  for (int i = 0; i < n; i++) {
    int num_of_card;
    cin >> num_of_card;
    min_heap.push(num_of_card);
  }

  int result = 0;

  while (min_heap.size() > 1) {
    int a, b;
    a = min_heap.top(); min_heap.pop();
    b = min_heap.top(); min_heap.pop();

    result += a + b;
    min_heap.push(a + b);
  }

  cout << result;
}
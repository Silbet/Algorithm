#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int avrage(vector<int> arr) {
  double result = 0;

  for (int i = 0; i < arr.size(); i++) {
    result += arr[i];
  }

  if (result / arr.size() > 0) return (int)(result / arr.size() + 0.5);
  else return (int)(result / arr.size() - 0.5);
}

int median(vector<int> arr) {
  return arr[arr.size()/2];
}

bool compare(pair<int, int> a, pair<int, int> b) {
  return a.second > b.second;
}

int mostNum(vector<int> arr) {
  int result;
  vector<pair<int, int>> v; // <정수 값, 해당 정수의 개수>

  v.push_back({arr[0], 1});

  int arrIndex = 0;
  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] == arr[i-1]) {
      v[arrIndex].second++;
    }
    else {
      arrIndex++;
      v.push_back({arr[i], 1});
    }
  }

  sort(v.begin(), v.end(), compare);
  if (v.size() == 1) result = v[0].first;
  else if (v[0].second == v[1].second) result = v[1].first;
  else result = v[0].first;

  return result;
}

int range(vector<int> arr) {
  return arr[arr.size() - 1] - arr[0];
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int numCnt;
  cin >> numCnt;

  vector<int> arr(numCnt);
  for (int i = 0; i < numCnt; i++) {
    cin >> arr[i];
  }
  
  sort(arr.begin(), arr.end());

  cout << avrage(arr) << "\n" << median(arr) << "\n" << mostNum(arr) << "\n" << range(arr) << "\n";
}


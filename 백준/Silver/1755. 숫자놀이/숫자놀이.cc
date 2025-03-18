#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

struct num {
  int intNum;
  string stringNum;
};

bool compare(num a, num b) {
  return a.stringNum < b.stringNum;
}

string number[10] = { "zero", "one", "two", "three", "four",
  "five", "six", "seven", "eight", "nine" };

string convertNumToString(string num) {
  string result = "";
  for (int i = 0; i < num.size(); i++) {
    for (int j = 0; j < 10; j++) {
      if (num[i] == j + 48) {
        result += number[j];
        break;
      }
    }
  }
  return result;
}

int main() {
  vector<num> v;
  int minRange, maxRange;
  cin >> minRange >> maxRange;
  for (int i = minRange; i <= maxRange; i++) {
    num tmp;
    tmp.intNum = i;
    tmp.stringNum = convertNumToString(to_string(i));
    v.push_back(tmp);
  }

  sort(v.begin(), v.end(), compare);

  for (int i = 0; i < v.size(); i++) {
    cout << v[i].intNum << " ";

    if (i % 10 == 9) cout << "\n";
  }
}
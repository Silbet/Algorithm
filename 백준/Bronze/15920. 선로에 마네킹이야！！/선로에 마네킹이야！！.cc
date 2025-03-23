// 15920. 선로에 마네킹이야!!
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
  int activityCnt;
  cin >> activityCnt;

  string activity;
  cin >> activity;

  int time = 0;
  bool lever = false;
  int multiTrack = false;
  for (int i = 0; i < activityCnt; i++) {

    if (activity[i] == 'W') {
      time++;
    }
    else {
      if (time == 0) lever = !lever;
      else if (time == 1) multiTrack = true;
    }



    if (time >= 2) {
      if (multiTrack) cout << 6;
      else if (lever) cout << 1;
      else cout << 5;
      break;
    }

    if (i == activityCnt - 1) cout << 0;
  }


}
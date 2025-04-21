// 7983. 내일 할거야
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Task {
  int task_day;
  int task_deadline;
};

bool compare(Task a, Task b) {
  return a.task_deadline > b.task_deadline;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int task_cnt;
  cin >> task_cnt;

  vector<Task> task(task_cnt);
  for (int i = 0; i < task_cnt; i++) {
    cin >> task[i].task_day >> task[i].task_deadline;
  }

  sort(task.begin(), task.end(), compare);


  int completed_day = task[0].task_deadline - task[0].task_day;
  for (int i = 1; i < task_cnt; i++) {
    completed_day = min(completed_day, task[i].task_deadline) - task[i].task_day;
  }
  cout << completed_day;

}
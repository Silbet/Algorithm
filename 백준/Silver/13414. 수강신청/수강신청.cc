#include <iostream>
#include <unordered_map>
#include <list>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K, L;
    cin >> K >> L;

    list<string> queue; // 대기열
    unordered_map<string, list<string>::iterator> position; // 학번 → iterator

    for (int i = 0; i < L; ++i) {
        string student;
        cin >> student;

        // 이미 있으면 지우고 다시 넣기 (맨 뒤로)
        if (position.find(student) != position.end()) {
            queue.erase(position[student]);
        }
        queue.push_back(student);
        position[student] = --queue.end(); // 새로운 위치 저장
    }

    // 앞에서부터 최대 K명 출력
    int count = 0;
    for (const auto& student : queue) {
        if (count >= K) break;
        cout << student << '\n';
        count++;
    }

    return 0;
}

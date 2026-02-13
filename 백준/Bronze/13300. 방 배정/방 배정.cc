// 13300. 방 배정
#include<iostream>
using namespace std;

int student[2][7];

int main() {
    // 같은 성별끼리 방 배정
    // 한 방에 같은 학년만
    
    int n, room_max;
    cin >> n >> room_max;

    for (int i = 0; i < n; i++) {
        int gender, grade;
        cin >> gender >> grade;
        student[gender][grade]++;
    }

    int room_count = 0;
    for (int i = 0; i <= 1; i++) {
        for (int j = 1; j <= 6; j++) {
            // 해당 학생 수가 0명이면 continue
            if (student[i][j] == 0) continue;

            room_count += ((student[i][j] - 1) / room_max) + 1; 
        }
    }
    cout << room_count;
}
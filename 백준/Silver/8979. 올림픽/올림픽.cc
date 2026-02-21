#include<iostream>
using namespace std;

int id[1005];
int gold[1005];
int silver[1005];
int bronze[1005];

int main() {
    int n, k;
    cin >> n >> k;

    int target_idx = 0;
    // 데이터 입력 및 타겟 국가의 인덱스 찾기
    for (int i = 0; i < n; i++) {
        cin >> id[i] >> gold[i] >> silver[i] >> bronze[i];
        if (id[i] == k) {
            target_idx = i;
        }
    }

    int rank = 1;
    // 처음부터 끝까지 돌면서 나보다 메달이 많은 국가의 수를 센다
    for (int i = 0; i < n; i++) {
        if (gold[i] > gold[target_idx]) {
            rank++;
        } else if (gold[i] == gold[target_idx]) {
            if (silver[i] > silver[target_idx]) {
                rank++;
            } else if (silver[i] == silver[target_idx]) {
                if (bronze[i] > bronze[target_idx]) {
                    rank++;
                }
            }
        }
    }

    cout << rank << "\n";
    return 0;
}
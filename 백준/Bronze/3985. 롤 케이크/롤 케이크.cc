// 3985. 롤 케이크
#include<iostream>
using namespace std;

bool rollcake[1005];

int main() {
    int length;
    cin >> length;

    int n;
    cin >> n;

    int expect = 0;
    int expect_viewer = 0;
    int real = 0;
    int real_viewer = 0;
    for (int i = 1; i <= n; i++) {
        int st, en;
        cin >> st >> en;

        if (en - st + 1 > expect) {
            expect = en - st + 1;
            expect_viewer = i;
        }

        int select = 0;
        for (int j = st; j <= en; j++) {
            if (rollcake[j] == 1) continue;
            
            select++;
            rollcake[j] = 1;
        }

        if (select > real) {
            real = select;
            real_viewer = i;
        }
    }

    cout << expect_viewer << "\n" << real_viewer;
}
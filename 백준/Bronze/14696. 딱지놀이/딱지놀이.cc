// 14696. 딱지놀이
#include<iostream>
using namespace std;

int card[2][5];

void initCard() {
    for (int i = 0; i <= 1; i++) {
        for (int j = 1; j <= 4; j++) {
            card[i][j] = 0;
        }
    }
}

void drawCard(int child, int cardCount) {
    for (int i = 0; i < cardCount; i++) {
            int score;
            cin >> score;
            card[child][score]++;
        }
}

void compareCard() {
    for (int i = 4; i >= 1; i--) {
        if (card[0][i] == card[1][i]) {
            if (i == 1) cout << "D";
            continue;
        }
        if (card[0][i] > card[1][i]) cout << "A";
        if (card[0][i] < card[1][i]) cout << "B";
        break;
    }
    cout << "\n";
}

int main() {
    int n;
    cin >> n;

    while(n--) {
        initCard();

        int a, b;

        cin >> a;
        drawCard(0, a);
        cin >> b;
        drawCard(1, b);

        compareCard();
    }
}
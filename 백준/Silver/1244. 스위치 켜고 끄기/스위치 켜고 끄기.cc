    // 1244. 스위치 켜고 끄기
    #include<iostream>
    using namespace std;

    bool switches[105];
    int n;

    void manLogic(int number) {
        for (int i = number; i <= n; i += number) {
            switches[i] = !switches[i];
        }
    }

    void womanLogic(int number) {
        
        int st, en;
        st = en = number;

        switches[number] = !switches[number];
        while (1) {
            if (st <= 1 || en >= n) break;
            
            if (switches[--st] != switches[++en]) break;

            switches[st] = !switches[st];
            switches[en] = !switches[en];
        }
    }

    void changeSwitch(int gender, int number) {
        if (gender == 1) manLogic(number);
        if (gender == 2) womanLogic(number);
    }


    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> switches[i];
        }

        int numOfStudent;
        cin >> numOfStudent;

        while (numOfStudent--) {
            int gender, number;
            cin >> gender >> number;

            changeSwitch(gender, number);
        }

        for (int i = 1; i <= n; i++) {
            cout << switches[i] << " ";
            if (i % 20 == 0) cout << "\n";
        }
    } 
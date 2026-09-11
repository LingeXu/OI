//给选手程序看的用 cout，给评测员/自己看的用 cerr

#include <bits/stdc++.h>
using namespace std;

int main() {
    // 设定答案
    int n = 100;
    int secret = 42;          // 想改答案就改这里

    // 先告诉选手n
    cout << n << endl;

    int qcount = 0;
    const int MAXQ = 100;   // 想改询问次数上限就改这里

    while (true) {
        string op;

        if(!(cin >> op)) {
            // 程序意外结束
            cerr << "[judge] 选手程序退出，未给出答案" << endl;
            return 1;
        }

        if (op == "?") {
            int x;
            cin >> x;
            if(++qcount > MAXQ) {
                cerr << "询问次数超限" << endl;
                return 1;
            }

            if(x == secret) {
                cout << 0 << endl;
            } 
            else if(x < secret) {
                cout << 1 << endl;
            } 
            else    cout << -1 << endl;
            
        }

        else if (op == "!") {
            int ans;
            cin >> ans;

            if (ans == secret) {
                cerr << "AC, 询问次数 = " << qcount << endl;
                return 0;
            } 
            else {
                cerr << "WA, 你的答案 = " << ans << ", 正确答案 = " << secret << endl;
                return 1;
            }
        }

        else {
            cerr << "非法操作符: " << op << endl;
            return 1;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a[6] = {3,2,0,1,0,0};
    int q_cnt = 0;
    const int Q = 4;
    while(true) {
        char op;
        if(!(cin >> op)) {
            cerr << "选手未给出操作" << endl;
            return 1;
        }
        if(op == '?') {
            if(++q_cnt > Q) {
                cerr << "询问次数超限" << endl;
                return 1;
            }
            int x, y;
            cin >> x >> y;
            if (x < 1 || x > 6 || y < 1 || y > 6) {
                cerr << "非法下标" << endl;
                return 1;
            }
            if(a[x - 1] == a[y - 1])
                cout << 0 << endl;
            else    cout << 1 << endl;
        }
        else if(op == '!') {
            int x;
            cin >> x;
            if(x == 3 || x == 5 || x == 6) {
                cout << "猜对了！" << endl;
                return 0;
            }
            else {
                cout << "猜错了, 正确答案是3或5或6" << endl;
                return 1;
            }
        }
        else {
            cerr << "未定义操作符" << endl;
            return 1;
        }
    }
    return 0;
}
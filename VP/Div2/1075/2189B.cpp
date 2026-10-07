#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, x;
struct inf {
    int a, b, c;
    int circle;
};
bool cmp(inf x, inf y) {
    return x.circle > y.circle;
}
void solve() {
    cin >> n >> x;
    vector<inf> jump(n);
    int init = 0;
    for(int i = 0; i < n; i++) {
        cin >> jump[i].a >> jump[i].b >> jump[i].c;
        init += jump[i].a * (jump[i].b - 1);
        jump[i].circle = jump[i].a * (jump[i].b - 1) + (jump[i].a - jump[i].c);
    }
    if(init >= x) {
        cout << 0 << '\n';
        return;
    }
    else {
        int remain = x - init;

        //cout << "remain = " << remain << '\n';

        sort(jump.begin(), jump.end(), cmp);

        //cout << "test : " << jump[0].circle << '\n';

        if(jump[0].circle <= 0) {
            cout << -1 << '\n';
            return;
        }
        int round = remain / jump[0].circle;
        if(remain % jump[0].circle == 0) {
            cout << round << '\n';
            return;
        }
        else {
            cout << round + 1 << '\n';
            return;
        }

    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)  solve();
    return 0;
}
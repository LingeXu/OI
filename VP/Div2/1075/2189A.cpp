#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int n, h, l;
    while(t--) {
        cin >> n >> h >> l;
        int can1 = 0, can2 = 0;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if(x <= h)  can1++;
            if(x <= l)  can2++;
        }
        int mx = max(can1, can2), mn = min(can1, can2);
        if(mx - mn >= mn) {
            cout << mn << '\n';
            continue;
        }
        else {
            cout << mx - mn + (mn - (mx - mn)) / 2 << '\n';
            continue;
        }
    }
    return 0;
}
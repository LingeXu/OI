#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int ans1 = 0, ans2 = 0, ans3 = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        int tmp = 1000 - x % 1000;
        if(tmp == 1000) {
            continue;
        }
        ans1 += tmp / 100;
        ans2 += tmp % 100 / 10;
        ans3 += tmp % 10;
    }
    cout << ans3 << ' ' << ans2 << ' ' << ans1;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int cnt_0 = 0, cnt_1 = 0;
        for(int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if(x == 0)  cnt_0++;
            else    cnt_1++;
        }
        if(cnt_1 >= cnt_0) {
            cout << "Bessie\n";
            continue;
        }
        cout << "Elsie\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int  main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for(int i = 1;i <= n; i++) {
        
            int x;
            cin >> x;
            if(x & 1) {
                cnt1++;

            }
            else {
                if(x % 4 == 0)  cnt0++;
                else    cnt2++;
            }
        }
        cout << max(max(cnt0, cnt1), cnt2) << '\n';
    }

    return 0;
}
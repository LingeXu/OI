#include <bits/stdc++.h>
#define N 1000010
using namespace std;
int n, m;
int a[N], last[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        //last[a[i]] = i;
    }
    for(int i = 1; i <= m; i++) {
        int L;
        cin >> L;
        memset(last, 0, sizeof(last));
        int j = 0, ans = 0, cnt = 0;
        for(int i = 1; i <= n - L + 1; i++) {
            while(j <= n && j - i + 1 < L) {
                j++;
                if(last[a[j]] < i) 
                    cnt++;
                last[a[j]] = j;
            }
            ans += cnt;
            if(j == n)
                break;
            if(j - i + 1 == L) {
                if(last[a[i]] == i) {
                    last[a[i]] = 0;
                    cnt--;
                }
            }
        }  
        cout << ans << '\n'; 
    }
    return 0;
}
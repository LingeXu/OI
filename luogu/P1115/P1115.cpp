#include <bits/stdc++.h>
#define N 200020
#define INF 0x3f3f3f3f
using namespace std;
int n;
int a[N], dp[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)  cin >> a[i];
    int ans = -INF;
    dp[0] = a[0];
    for(int i = 1; i < n; i++) {
        dp[i] = max(a[i], dp[i - 1] + a[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}
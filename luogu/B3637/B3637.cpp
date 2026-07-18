#include <bits/stdc++.h>
#define N 5050
using namespace std;
int n, ans = 0;
int a[N], dp[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)    dp[i] = 1;
    for(int i = 2; i <= n; i++) 
        for(int j = 1; j < i; j++)
            if(a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + 1);
    for(int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);
    cout << ans;
    return 0;
}
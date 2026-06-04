#include<bits/stdc++.h>
#define N 20020
using namespace std;
int n;
int dp[N][2];
struct inf{
    int Left, Right, Length;
}a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].Left >> a[i].Right;
        a[i].Length = a[i].Right - a[i].Left;
    }
    dp[1][1] = a[1].Right - 1;
    dp[1][0] = a[1].Right + a[1].Length - 1;
    for(int i = 2; i <= n; i++){
        dp[i][0] = min(dp[i - 1][0] + abs(a[i].Right - a[i - 1].Left), dp[i - 1][1] + abs(a[i].Right - a[i - 1].Right)) + a[i].Length + 1;
        dp[i][1] = min(dp[i - 1][0] + abs(a[i].Left - a[i - 1].Left), dp[i - 1][1] + abs(a[i].Left - a[i - 1].Right)) + a[i].Length + 1;
    }
    cout << min(dp[n][0] + n - a[n].Left, dp[n][1] + n - a[n].Right);
    return 0;
}
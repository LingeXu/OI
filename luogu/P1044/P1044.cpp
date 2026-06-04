#include<iostream>
#include<cstring>
#define N 19
typedef long long ll;
using namespace std;
ll dp[N];
int main(){
    int n;
    cin >> n;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1, dp[1] = 1;
    for(int i = 2; i <= n; i++)
        for(int j = 0; j <= i - 1; j++)
            dp[i] += dp[j] * dp[i - j - 1];
    cout << dp[n];
}
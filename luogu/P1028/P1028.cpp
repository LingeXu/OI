#include<iostream>
#define N 1010
typedef long long ll;
using namespace std;
ll dp[N];
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        dp[i] = 1;
    for(int i = 2; i <= n; i++)
        for(int j = 1; j <= i / 2; j++)
            dp[i] += dp[j];
    cout << dp[n];
    return 0;
}
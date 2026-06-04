#include<iostream>
#include<cstring>
#define N 1010
#define W 10010
const int MOD = 1e9 + 7;
using namespace std;
int n, w;
int a[N], dp[N * W];
bool vis[N * W];
int GetAns(int x){
    if(vis[x])  return dp[x];
    vis[x] = true;
    if(x == 0)  return dp[0] = 1;
    for(int i = 0; i < n; i++)
        if(a[i] <= x)
            dp[x] = (dp[x]+ GetAns(x - a[i])) % MOD;
    return dp[x];
}
int main(){
    cin >> n >> w;
    for(int i = 0; i < n; i++)  cin >> a[i];
    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    cout << GetAns(w);
    return 0;
}
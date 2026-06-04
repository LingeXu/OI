#include<iostream>
#define N 1010
#define W 10010
#define INF 0x3f3f3f3f
using namespace std;
int n, w;
int a[N], dp[W];
int GetAns(int x){
    if(x == 0)  return dp[0] = 0;
    if(dp[x] != -1)  return dp[x];
    int ans = INF;
    for(int i = 0; i < n; i++)
        if(a[i] <= x)
            ans = min(ans, GetAns(x - a[i]) + 1); 
    return dp[x] = ans;
}
int main(){
    cin >> n >> w;
    for(int i = 0; i < n; i++)  cin >> a[i];
    memset(dp, -1, sizeof(dp));
    GetAns(w);
    cout << dp[w];
    return 0;
}
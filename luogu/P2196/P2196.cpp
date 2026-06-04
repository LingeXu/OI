#include<iostream>
#include<vector>
#include<algorithm>
#define N 25
using namespace std;
int n;
int val[N], dp[N], last[N];
bool has_edge[N][N], start[N];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> val[i];
    for(int i = 1; i <= n - 1; i++)
        for(int j = i + 1; j <= n; j++)
            cin >> has_edge[i][j];
    for(int i = 1; i <= n; i++){
        dp[i] = val[i];
        last[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(has_edge[j][i]){
                if(dp[j] + val[i] > dp[i]){
                    dp[i] = dp[j] + val[i];
                    last[i] = j;
                }
            }
        }
    }
    int ans = 0, final_node;
    for(int i = 1; i <= n; i++){
        if(dp[i] > ans){
            ans = dp[i];
            final_node = i;
        }
    }
    vector<int> route;
    int now = final_node;
    while(1){
        route.push_back(now);
        now = last[now];
        if(now == 0)    break;
    }
    reverse(route.begin(), route.end());
    for(auto it = route.begin(); it != route.end(); it++)   cout << *it << ' ';
    cout << '\n';
    cout << ans;
    return 0;
}
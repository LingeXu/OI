#include<bits/stdc++.h>
#define N 32010
#define M 65
using namespace std;
int n, m;
int v[M], p[M], q[M], dp[N];
map<int, int> mp;
struct inf{
    int cnt;
    int cost[4], val[4];
}staff[M];
int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
        cin >> v[i] >> p[i] >> q[i];
    int idx = 1;
    for(int i = 1; i <= m; i++) {
        if(q[i] == 0) {
            staff[idx].cost[0] = v[i];
            staff[idx].val[0] = v[i] * p[i];
            staff[idx].cnt++;
            mp[i] = idx;
            idx++;
        }
    }
    for(int i = 1; i <= m; i++) {
        if(q[i] != 0 && staff[mp[q[i]]].cnt == 1) {
            staff[mp[q[i]]].cost[1] = staff[mp[q[i]]].cost[0] + v[i];
            staff[mp[q[i]]].val[1] = staff[mp[q[i]]].val[0] + v[i] * p[i];
            staff[mp[q[i]]].cnt = 2;
        }
        else if(q[i] != 0 && staff[mp[q[i]]].cnt == 2) {
            staff[mp[q[i]]].cost[2] = staff[mp[q[i]]].cost[0] + v[i];
            staff[mp[q[i]]].val[2] = staff[mp[q[i]]].val[0] + v[i] * p[i];
            staff[mp[q[i]]].cnt = 4;
            staff[mp[q[i]]].cost[3] = staff[mp[q[i]]].cost[1] + v[i];
            staff[mp[q[i]]].val[3] = staff[mp[q[i]]].val[1] + v[i] * p[i];
        }
    }
    dp[0] = 0;
    for(int i = 1; i < idx; i++)
        for(int j = n; j >= 0; j--)
            for(int k = 0; k < staff[i].cnt; k++)
                if(j - staff[i].cost[k] >= 0)
                    dp[j] = max(dp[j], dp[j - staff[i].cost[k]] + staff[i].val[k]);
    cout << dp[n];
    return 0;
}
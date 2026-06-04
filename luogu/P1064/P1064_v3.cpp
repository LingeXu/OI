#include<bits/stdc++.h>
#define N 32010
#define M 65
using namespace std;
int n, m;
int p[M], q[M], v[M], dp[N];
struct inf{
    int size;
    vector<int> cost, importance, val, final_cost;
}staff[M];
map<int, int> mp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
        cin >> v[i] >> p[i] >> q[i];
    int main_staff = 0;
    for(int i = 1; i <= m; i++){
        if(q[i] == 0){
            mp[i] = main_staff;
            staff[main_staff].cost.push_back(v[i]);
            staff[main_staff].importance.push_back(p[i]);
            main_staff++;
        }
    }
    for(int i = 1; i <= m; i++){
        if(q[i] != 0){
            staff[mp[q[i]]].cost.push_back(v[i]);
            staff[mp[q[i]]].importance.push_back(p[i]);
        }
    }
    for(int i = 0; i < main_staff; i++){
        if(staff[i].cost.size() == 1){
            staff[i].size = 1;
            staff[i].val.push_back(staff[i].cost[0] * staff[i].importance[0]);
            staff[i].final_cost.push_back(staff[i].cost[0]);
        }
        else if(staff[i].cost.size() == 2){
            staff[i].size = 2;
            staff[i].val.push_back(staff[i].cost[0] * staff[i].importance[0]);
            staff[i].val.push_back(staff[i].cost[0] * staff[i].importance[0] + staff[i].cost[1] *staff[i].importance[1]);
            staff[i].final_cost.push_back(staff[i].cost[0]);
            staff[i].final_cost.push_back(staff[i].cost[0] + staff[i].cost[1]);
        }
        else{
            staff[i].size = 4;
            staff[i].val.push_back(staff[i].cost[0] * staff[i].importance[0]);
            staff[i].val.push_back(staff[i].cost[0] * staff[i].importance[0] + staff[i].cost[1] * staff[i].importance[1]);
            staff[i].val.push_back(staff[i].cost[0] * staff[i].importance[0] + staff[i].cost[2] * staff[i].importance[2]);
            staff[i].val.push_back(staff[i].cost[0] * staff[i].importance[0] + staff[i].cost[1] * staff[i].importance[1] + staff[i].cost[2] * staff[i].importance[2]);
            staff[i].final_cost.push_back(staff[i].cost[0]);
            staff[i].final_cost.push_back(staff[i].cost[0] + staff[i].cost[1]);
            staff[i].final_cost.push_back(staff[i].cost[0] + staff[i].cost[2]);
            staff[i].final_cost.push_back(staff[i].cost[0] + staff[i].cost[1] + staff[i].cost[2]);
        }
    }
    for(int i = 0; i < main_staff; i++)
        for(int j = n; j >= 0; j--)
            for(int k = 0; k < staff[i].final_cost.size(); k++)
                if(j - staff[i].final_cost[k] >= 0)
                    dp[j] = max(dp[j], dp[j - staff[i].final_cost[k]] + staff[i].val[k]);
    cout << dp[n];
    return 0;
}
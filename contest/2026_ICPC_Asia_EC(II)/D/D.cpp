#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
const int N = 1 << 19;
int n, q;
int sz[N], constrain[N], f[N];
vector<int> graph[N];
bool is_ancestor(int u, int v) {
    if(u == v)  return false;
    if(u > v)   swap(u, v);
    while(v > u)
        v >>= 1;
    if(u == v)  return true;
    return false;
}
void init(int u) {
    int child1 = u << 1, child2 = (u << 1) + 1;
    if(child1 >= (1 << (n + 1))) {
        sz[u] = 1;
        return;
    }
    init(child1);
    init(child2);
    sz[u] = sz[child1] + sz[child2];
}
void dfs(int u, int pre) {
    if(constrain[u] != 0 && pre != 0)   graph[pre].push_back(u);
    int child1 = 2 * u, child2 = 2 * u + 1;
    if(child1 >= (1 << (n + 1)))
        return;
    if(constrain[u] != 0) {
        dfs(child1, u);
        dfs(child2, u);
    }
    else {
        dfs(child1, pre);
        dfs(child2, pre);
    }
}
bool judge(int u) {
    bool res = true;
    for(int v : graph[u]) {
        if(constrain[v] > constrain[u])
            return false;
        res &= judge(v);
        if(res == false)    return false;
    }
    return true;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    vector< vector<int> > record((1 << n) + 1, vector<int>());
    bool has_solution = true;
    while(q--) {
        int u, x;
        cin >> u >> x;
        if(constrain[u] != 0 && constrain[u] != x) 
            has_solution = false;
        if(constrain[u] != 0 && constrain[u] == x)  continue;
        constrain[u] = x;
        if(!(x == (1 << n) && u == 1))
            record[x].push_back(u);
    }
    if(!has_solution) {
        //cout << "1 :" << '\n';
        cout << 0;
        return 0;
    }
    if(constrain[1] != 0 && constrain[1] != (1 << n)) {
        //cout << "2 :" << '\n';
        cout << 0;
        return 0;
    }
    constrain[1] = (1 << n);
    record[1 << n].push_back(1);
    for(int i = 1; i <= (1 << n); i++) {
        if(record[i].empty())   continue;
        if((int)record[i].size() > n + 1) {
            //cout << "3 :" << '\n';
            cout << 0;
            return 0;
        }
        sort(record[i].begin(), record[i].end());
        for(int j = 0; j < (int)record[i].size() - 1; j++) {
            if(!is_ancestor(record[i][j], record[i][j + 1])) {
                //cout << "4 :" << '\n';
                cout << 0;
                return 0;
            }
        }
    }
    init(1);
    dfs(1, 0);
    if(!judge(1)) {
        //cout << "5 :" << '\n';
        cout << 0;
        return 0;
    }
    for(int i = 1; i < (1 << (n + 1)); i++) {
        if(constrain[i] != 0) {
            f[i] = sz[i];
            /*if(f[i] == 1) {
                f[i] = 0;
                continue;
            }*/
            for(int v : graph[i])
                f[i] -= sz[v];
        }   
    }   

    /*cout << "Test : " << '\n';
    for(int i = 1; i < (1 << (n + 1)); i++)
        cout << "i = " << i << ", f[i] = " << f[i] << '\n';*/
     
    int ans = 1, empty = 0;
    for(int i = (1 << n); i >= 1; i--) {
        if(!record[i].empty()) {
            ans = ans * f[record[i].back()] % MOD;
            for(int idx : record[i])
                empty += f[idx];
            empty--;
        }
        else {
            ans = ans * empty % MOD;
            empty--;
        }

        //cout << "empty = " << empty << '\n';
        
        if(empty < 0) {
            //cout << "6 :" << '\n';
            cout << 0;
            return 0;
        }
    }
    cout << ans;
    return 0;
}
#include <bits/stdc++.h>
#define N 53
using namespace std;
int n, group = 0;
int fa[N], deg[N];
int g[N][N];
bool exist[N];
vector<int> ans;
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void unite(int x, int y) {
    int rx = find(x), ry = find(y);
    if(rx != ry) {
        fa[rx] = ry;
        group--;
    }
}
int get_id(char c) {
    if(c >= 'a' && c <= 'z')
        return c - 'a' + 1 + 26;
    else
        return c - 'A' + 1;
}
void dfs(int u) {
    for(int i = 1; i <= 52; i++) {
        if(g[u][i] > 0) {
            g[u][i]--;
            g[i][u]--;
            dfs(i);
        }
    }
    ans.push_back(u);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    char c1, c2;
    for(int i = 1; i <= 52; i++)
        fa[i] = i;
    for(int i = 1; i <= n; i++) {
        cin >> c1 >> c2;
        int u = get_id(c1);
        int v = get_id(c2);
        if(!exist[u]) {
            group++;
            exist[u] = true;

            //cout << group << ' ';

        }
        if(!exist[v]) {
            group++;
            exist[v] = true;

            //cout << group << ' ';
            
        }
        g[u][v]++;
        g[v][u]++;
        deg[u]++;
        deg[v]++;
        unite(u, v);

        //cout << group << ' ';
            
    }

    //cout << group << '\n';

    if(group != 1) {
        cout << "No Solution";
        return 0;
    }
    int odd_deg_cnt = 0;
    for(int i = 1; i <= 52; i++)
        if(deg[i] & 1)
            odd_deg_cnt++;
    if(odd_deg_cnt != 0 && odd_deg_cnt != 2) {
        cout << "No Solution";
        return 0;
    }
    int start = -1;
    if(odd_deg_cnt == 0) {
        for(int i = 1; i <= 52; i++) {
            if(exist[i]) {
                start = i;
                break;
            }
        }
    }
    else if(odd_deg_cnt == 2) {
        for(int i = 1; i <= 52; i++) {
            if(deg[i] & 1) {
                start = i;
                break;
            }
        }
    }

    //cout << start << '\n';

    dfs(start);
    for(int i = ans.size() - 1; i >= 0; i--) {
        int x = ans[i];
        if(x <= 26)
            cout << char(x + 'A' - 1);
        else
            cout << char(x + 'a' - 1 - 26);
    }
    return 0;
}
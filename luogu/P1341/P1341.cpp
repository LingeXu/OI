#include <bits/stdc++.h>
#define N 53
using namespace std;
int n, group = 0;
int deg[N], fa[N];
bool exist[N], vis[N];
vector<int> graph[N], ans;
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void unite(int x, int y) {
    int rx = find(x), ry = find(y);
    if(rx != ry) {
        group--;
        fa[rx] = ry;
    }
}
void dfs(int u) {
    vis[u] = true;
    ans.push_back(u);
    for(int j : graph[u]) 
        if(!vis[j]) 
            dfs(j);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    char c1, c2;
    int id1, id2;
    memset(deg, 0, sizeof(deg));
    for(int i = 1; i <= 52; i++)
        fa[i] = i;
    for(int i = 1; i <= n; i++) {
        cin >> c1 >> c2;
        if(c1 <= 'z')
            id1 = c1 - 'a' + 1;
        else
            id1 = c1 - 'A' + 1 + 26;
        if(c2 <= 'z')
            id2 = c2 - 'a' + 1;
        else
            id2 = c2 - 'A' + 1 + 26;
        if(!exist[id1]) {
            exist[id1] = true;
            group++;
        }
        if(!exist[id2]) {
            exist[id2] = true;
            group++;
        }
        graph[id1].push_back(id2);
        graph[id2].push_back(id1);
        deg[id1]++;
        deg[id2]++;
        unite(id1, id2);
    }
    if(group != 1) {
        cout << "No Solution";
        return 0;
    }
    int odd_deg_cnt = 0, start = 0x3f3f3f3f;
    for(int i = 1; i <= 52; i++) {
        if(deg[i] & 1) {
            odd_deg_cnt++;
            start = min(start, i);
        }
    }
    if(odd_deg_cnt != 0 && odd_deg_cnt != 2) {
        cout << "No Solution";
        return 0;
    }
    if(odd_deg_cnt == 0) 
        for(int i = 1; i <= 52; i++)
            if(exist[i])
                start = i;
    memset(vis, 0, sizeof(vis));
    dfs(start);
    for(auto it = ans.begin(); it != ans.end(); it++) {
        if(*it <= 26)
            cout << char(*it + 'a' - 1);
        else
            cout << char(*it + 'A' - 1 - 26);
    }
    return 0;
}
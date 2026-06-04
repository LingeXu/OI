#include <bits/stdc++.h>
#define N 155
#define M 5050
using namespace std;
int n, m, cnt = 0;
int dfn[N], low[N];
bool instack[N];
vector<int> graph[N];
priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > ans;
void tarjan(int u, int father) {
    dfn[u] = low[u] = ++cnt;
    for(int to : graph[u]) {
        if(to == father)    continue;
        if(!dfn[to]) {
            tarjan(to, u);
            low[u] = min(low[u], low[to]);
            if(low[to] > dfn[u])
                ans.push({min(u, to), max(u, to)});
        }
        else    low[u] = min(low[u], dfn[to]);
    }
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    tarjan(1, 0);
    while(!ans.empty()) {
        auto e = ans.top();
        ans.pop();
        cout << e.first << ' ' << e.second << '\n';
    }
    return 0;
}
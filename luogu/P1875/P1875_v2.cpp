#include<iostream>
#include<vector>
#define N 1010
using namespace std;
int n;
int price[N];
vector< pair<int, int> > graph[N];
pair<int, int> inf[N];
bool vis[N];
void dfs(int x) {
    if (vis[x]) return;
    vis[x] = true;
    
    if (graph[x].empty()) {
        inf[x] = {price[x], 1};
        return;
    }
    
    int best = 1e9;
    int ways = 0;
    
    for (auto &e : graph[x]) {
        int u = e.first;
        int v = e.second;
        dfs(u);
        dfs(v);
        
        int sum = inf[u].first + inf[v].first;
        
        if (sum < best) {
            best = sum;
            ways = inf[u].second * inf[v].second;
        } else if (sum == best) {
            ways += inf[u].second * inf[v].second;
        }
    }
    
    // 与直接购买比较
    if (price[x] < best) {
        inf[x] = {price[x], 1};
    } else if (price[x] > best) {
        inf[x] = {best, ways};
    } else {
        inf[x] = {best, ways + 1};
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)  cin >> price[i];
    int a, b, c;
    while(cin >> a >> b >> c)   graph[c].push_back({a, b});
    for(int i = 0; i < n; i++)  inf[i] = {price[i], 1};
    dfs(0);
    cout << inf[0].first << ' ' << inf[0].second;
    return 0;
}
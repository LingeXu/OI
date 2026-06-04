#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define N 50010
#define INF 0x3f3f3f3f
using namespace std;
int n, best, id = 1;
int sz[N], level[N], ans[N];
vector<int> graph[N];
void bfs1(){
    queue<int> q;
    q.push(1);
    memset(ans, 0, sizeof(ans));
    memset(level, -1, sizeof(level));
    level[1] = 0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int neighbor : graph[x]){
            if(level[neighbor] == -1){
                level[neighbor] = level[x] + 1;
                ans[1] += level[neighbor];
                q.push(neighbor);
            }
        }
    }
}
void dfs(int u, int fa){
    sz[u] = 1;
    for(int neighbor : graph[u]){
        if(neighbor == fa)  continue;
        dfs(neighbor, u);
        sz[u] += sz[neighbor];
    }
}
void bfs2(){
    queue<int> q;
    q.push(1);
    bfs1();
    best = ans[1];
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int neighbor : graph[x]){
            if(ans[neighbor] == 0){
                int change = n - 2 * sz[neighbor];
                ans[neighbor] = ans[x] + change;
                if(change < 0)  q.push(neighbor);
                if(ans[neighbor] < best || (ans[neighbor] == best && neighbor < id)){
                    best = ans[neighbor];
                    id = neighbor;
                }
            }
        }
    }
    cout << id << ' ' << best;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n - 1; i++){
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    dfs(1, 0);
    bfs2();
    return 0;
}
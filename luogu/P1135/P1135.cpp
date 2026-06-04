#include<iostream>
#include<queue>
#include<cstring>
#define N 210
using namespace std;
int n, a, b, ans = 0;
int k[N], level[N];
bool ok;
bool vis[N];
/*void dfs(int u, int cnt){
    if(u < 1 || u > n)  return;
    if(u == b){
        cout << cnt;
        return;
    }
    dfs(u + k[u - 1], cnt + 1);
    dfs(u - k[u - 1], cnt + 1);
}*/

void bfs(int u){
    memset(level, -1, sizeof(level));
    queue<int> q;
    q.push(u);
    level[u] = 0;
    vis[u] = true;
    while(!q.empty()){
        int x = q.front();
        if(x == b){
            ok = true;
            cout << level[x];
            return;
        }
        q.pop();
        int up = x + k[x - 1], down = x - k[x - 1];

        if(!vis[up] && up > 0 && up <= n){
            q.push(up);
            level[up] = level[x] + 1;
            vis[up] = true;
            //cout << up << ' ';
        }
        if(!vis[down] && down > 0 && down <= n){
            q.push(down);
            level[down] = level[x] + 1;
            vis[down] = true;
            //cout << down << ' ';
        }
    }
}
int main(){
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++)  cin >> k[i];
    //dfs(a, 0);
    bfs(a);
    if(!ok)
        cout << -1;
    return 0;
}
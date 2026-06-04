#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#define N 110
using namespace std;
int fa[N], lc[N], rc[N], dep[N], cnt[N];
void bfs(int u){
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(lc[x] != 0){
            dep[lc[x]] = dep[x] +1;
            q.push(lc[x]);
        }
        if(rc[x] != 0){
            dep[rc[x]] = dep[x] +1;
            q.push(rc[x]);
        }
    }
    return;
}
int main(){
    int n;
    cin >> n;
    dep[1] = 1;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        fa[v] = u;
        if(lc[u] != 0)
            rc[u] = v;
        else
            lc[u] = v;
    }
    bfs(1);
    int depth = 0;
    for(int i = 1; i <= n; i++)
        depth = max(depth, dep[i]);
    cout << depth << '\n';

    for(int i = 1; i <= depth; i++)
        for(int j = 1; j <= n; j++)
            if(dep[j] == i)
                cnt[i]++;
    sort(cnt + 1, cnt + depth + 1);
    cout << cnt[depth] << '\n';

    int x, y;
    cin >> x >> y;
    int up, down, ans = 0;
    if(dep[x] > dep[y]){
        up = dep[x] - dep[y];
        ans += 2*up;
        for(int i = 1; i <= up; i++)
            x = fa[x];
        while(x != y){
            x = fa[x];
            y = fa[y];
            ans += 3;
        }
        cout << ans;
        return 0;
    }
    else if(dep[x] < dep[y]){
        down = dep[y] - dep[x];
        ans += down;
        for(int i = 1; i <= down; i++)
            y = fa[y];
        while(x != y){
            x = fa[x];
            y = fa[y];
            ans += 3;
        }
        cout << ans;
        return 0;
    }
    else{
        while(x != y){
            x = fa[x];
            y = fa[y];
            ans += 3;
        }
        cout << ans;
        return 0;
    }
    return 0;
}
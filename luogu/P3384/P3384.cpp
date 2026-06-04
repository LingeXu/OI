#include<iostream>
#include<vector>
#define N 100010
#define LOG 18
using namespace std;
int n, m, r, p;
vector<int> graph[N];
int NodeWeight[N], depth[N], fa[N][LOG];

void dfs(int u, int father){
    fa[u][0] = father;
    depth[u] = depth[father] + 1;
    for(int i = 1; i < LOG; i++)    fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for(int neighbor : graph[u]){
        if(neighbor == father)  continue;
        dfs(neighbor, u);
    }
}
int lca(int x, int y){
    if(depth[x] < depth[y])
        swap(x, y);
    for(int i = LOG - 1; i >= 0; i--)
        if(depth[fa[x][i]] >= depth[y])
            x = fa[x][i];
    if(x == y)  return x;
    for(int i = LOG - 1; i >= 0; i--){
        if(fa[x][i] != fa[y][i]){
            x = fa[x][i];
            y = fa[y][i];
        }    
    }
    return fa[x][0];
}
void OP1(int x, int y, int z){
    int rt = lca(x, y);
    while(1){
        NodeWeight[x] += z;
        if(x == rt)  break;
        x = fa[x][0];
    }
    while(1){
        if(y == rt) break;
        NodeWeight[y] += z;
        y = fa[y][0];
    }
}
void OP2(int x, int y){
    int sum = 0;
    int rt = lca(x, y);
    while(1){
        sum += NodeWeight[x];
        if(x == rt)
            break;
        x = fa[x][0];
    }
    while(1){
        if(y == rt)
            break;
        sum += NodeWeight[y];
        y = fa[y][0];
    }
    cout << sum << '\n';
}
void OP3(int x, int z){
    NodeWeight[x] += z;
    for(int neighbor : graph[x])
        if(depth[neighbor] > depth[x])
            OP3(neighbor, z);
}
void OP4(int x, int &sum){
    sum += NodeWeight[x];
    for(int neighbor : graph[x])
        if(depth[neighbor] > depth[x])
            OP4(neighbor, sum);
}
int main(){
    cin >> n >> m >> r >> p;
    for(int i = 1; i <= n; i++)
        cin >> NodeWeight[i];
    for(int i = 1; i <= n - 1; i++){
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    dfs(r, 0);
    for(int i = 1; i <= m; i++){
        int op;
        cin >> op;
        if(op == 1){
            int x, y, z;
            cin >> x >> y >> z;
            OP1(x, y, z);
        }
        else if(op == 2){
            int x, y;
            cin >> x >> y;
            OP2(x, y);
        }
        else if(op == 3){
            int x, z;
            cin >> x >> z;
            OP3(x, z);
        }
        else{
            int x;
            cin >> x;
            int sum = 0;
            OP4(x, sum);
            cout << sum << '\n';
        }
    }
    return 0;
}
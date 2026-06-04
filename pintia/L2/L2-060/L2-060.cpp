#include<iostream>
#include<vector>
#include<cstring>
#define N 10010
using namespace std;
bool vis[N];
vector< pair<int, int> > graph[N];
void dfs(int u){
    vis[u] = true;
    int maxp = 0, next_joint = -1;
    for(auto &e : graph[u]){
        if(!vis[e.second]){
            if(e.first > maxp || (e.first == maxp && e.second < next_joint) ){
                maxp = e.first;
                next_joint = e.second;
            }
        }
    }
    if(next_joint == -1)
        return;
    cout << "->" << next_joint;
    dfs(next_joint);
}
int main(){
    int n, m;
    cin >> n >> m;
    while(m > 0){
        int id1, id2, p;
        cin >> id1 >> id2 >> p;
        graph[id1].push_back({p, id2});
        m--;
    }
    int k;
    cin >> k;
    while(k > 0){
        int x;
        cin >> x;
        cout << x;
        memset(vis, 0, sizeof(vis));
        dfs(x);
        cout << '\n';
        k--;
    }
    return 0;
}
#include<iostream>
#include<vector>
#include<queue>
#define N 100010
#define INF 0x3f3f3f3f
using namespace std;
int minv[N];
vector< pair<int, int> > graph[N];
struct joint{
    int id, minv;
}j[N];
void bfs(int u){
    minv[u] = INF;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto &e : graph[x]){
            minv[e.second] = min(minv[x], e.first);
            q.push(e.second);
        }
    }
}
bool cmp(joint x, joint y){
    return x.minv > y.minv ||(x.minv == y.minv && x.id <y.id);
}
int main(){
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int from, val;
        cin >> from >> val;
        graph[from].push_back({val, i});
    }
    bfs(0);
    int now = 0;
    for(int i = 0; i < n; i++)
        if(graph[i].size() == 0)
            j[now++] = {i, minv[i]};
    sort(j, j + now, cmp);
    int minval = j[0].minv;
    cout << minval << '\n';
    int cnt = 0;
    for(int i = 0; i < now; i++){
        if(j[i].minv == minval){
            if(cnt == 0){
                cout << j[i].id;
                cnt++;
            }
            else    cout << " " << j[i].id;
        }
    }
    return 0;
}
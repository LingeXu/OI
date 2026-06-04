#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
#define N 20
#define INF 0x3f3f3f3f
using namespace std;
int n;
double ans = INF;
double d[N][N];
bool vis[N];
vector< pair<double, double> > pos;
void dfs(int u, double dis){
    if (dis >= ans) return;
    bool IsEnd = true;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            IsEnd = false;
            vis[i] = true;
            dfs(i, dis + d[u][i]);
            vis[i] = false;
        }
    }
    if(IsEnd)   ans = 1.0 * min(ans, dis);
}
int main(){
    cin >> n;
    pos.push_back({0.0, 0.0});
    for(int i = 1; i <= n; i++){
        double x, y;
        cin >> x >> y;
        pos.push_back({x, y});
    }
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            d[i][j] = d[j][i] = 1LL * sqrt((pos[i].first - pos[j].first) * (pos[i].first - pos[j].first) + (pos[i].second - pos[j].second) * (pos[i].second - pos[j].second));
    dfs(0, 0.0);
    cout << fixed << setprecision(2) << ans;
    return 0;
}
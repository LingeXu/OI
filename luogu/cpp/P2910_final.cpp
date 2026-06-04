#include <iostream>
#include <vector>
#include <cstring>
#define N 110
using namespace std;
int n, m, ans = 0;
int dist[N][N];
vector<int> tovisit;
vector< pair<int, int> > graph[N];
void Floyd(){
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a;
        cin >> a;
        tovisit.push_back(a);
    }
    memset(dist, 0x3f, sizeof(dist));
    for(int i = 1; i <= n; i++)
        dist[i][i] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int danger;
            cin >> danger;
            dist[i][j] = danger;
        }
    }
    Floyd();
    for(int i = 0; i < m - 1; i++)  ans += dist[tovisit[i]][tovisit[i + 1]];
    cout << ans;
    return 0;
}
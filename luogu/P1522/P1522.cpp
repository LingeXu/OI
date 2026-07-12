#include <bits/stdc++.h>
#define N 155
using namespace std;
int n;
char has_edge[N][N];
struct location {
    double x, y;
} node[N];   
vector< pair<double, int> > graph[N];
double GetDis(int id1, int id2) {
    double x1 = node[id1].x;
    double x2 = node[id2].x;
    double y1 = node[id1].y;
    double y2 = node[id2].y;
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> node[i].x >> node[i].y;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> has_edge[i][j];
            if(has_edge[i][j] == 1)
                graph[i].push_back({GetDis(i, j), j});
        }
    }
    return 0;
}
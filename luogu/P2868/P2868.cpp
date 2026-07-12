#include <bits/stdc++.h>
#define L 1010
using namespace std;
int l, p;
int val[L], cnt_update[L + 1];
double dis[L + 1];
bool inq[L + 1];
vector< pair<int, int> > graph[L];
vector< pair<double, int> > g[L + 1];
bool spfa(double x) {
    for(int i = 0; i <= l; i++)
        g[i].clear();
    memset(cnt_update, 0, sizeof(cnt_update));
    memset(inq, 0, sizeof(inq));
    for(int i = 1; i <= l; i++)
        dis[i] = 1e6;
    dis[0] = 0;
    for(int i = 1; i <= l; i++)
        for(auto& e : graph[i])
            g[i].push_back({x * e.first - val[e.second], e.second});
    for(int i = 1; i <= l; i++)
        g[0].push_back({0, i});
    queue<int> q;
    q.push(0);
    inq[0] = true;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        inq[x] = false;
        for(auto& e : g[x]) {
            if(dis[e.second] > dis[x] + e.first) {
                dis[e.second] = dis[x] + e.first;
                if(++cnt_update[e.second] > l)
                    return false;
                if(!inq[e.second]) {
                    q.push(e.second);
                    inq[e.second] = true;
                }
            }
        }
    }
    return true;
}
bool check(double x) {
    return !spfa(x);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> l >> p;
    for(int i = 1; i <= l; i++) 
        cin >> val[i];
    for(int i = 1; i <= p; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
    }
    double Left = 0, Right = 1e6, ans = -1;
    while(Left <= Right) {
        double mid = Left + (Right - Left) / 2;
        if(check(mid)) {
            ans = mid;
            Left = mid + 1e-10;
        }
        else    Right = mid - 1e-10;
    }
    if(ans == -1) {
        cout << 0;
        return 0;
    }
    cout << fixed << setprecision(2) << ans;
    return 0;
}
#include <bits/stdc++.h>
#define N 505
typedef long long ll;
using namespace std;
int n;
int p[N];
bool open[N];
ll dis[N][N];
vector<ll> res;
ll floyd(int x) {
    ll res = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            dis[i][j] = min(dis[i][j], dis[i][x] + dis[x][j]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(open[i] && open[j])
                res += dis[i][j];
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> dis[i][j];
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    for(int i = n; i >= 1; i--) {
        open[p[i]] = true;
        res.push_back(floyd(p[i]));
    }
    reverse(res.begin(), res.end());
    for(int i = 0; i < n; i++)
        cout << res[i] << ' ';
    return 0;
}
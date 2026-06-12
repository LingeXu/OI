#include <bits/stdc++.h>
#define N 1000010
#define LOG 61
typedef long long ll;
using namespace std;
int n, k;
ll m;
ll dist[N];
int fa[N][LOG];
vector<int> res;
void preprocess() {
    /*for(int i = 1; i <= n; i++) {
        if(i == 1)
            fa[i][0] = 2;
        else if(i == n)
            fa[i][0] = n - 1;
        else    fa[i][0] = (dist[i] - dist[i - 1] <= dist[i + 1] - dist[i] ? i : i + 1);
    }*/

    int l = 1, r = k + 1;
    for(int i = 1; i <= n; i++) {
        while(r + 1 <= n && dist[r + 1] - dist[i] < dist[i] - dist[l]) {
            l++;
            r++;
        }
        if(dist[i] - dist[l] >= dist[r] - dist[i])
            fa[i][0] = l;
        else
            fa[i][0] = r;
    }
    
    for(int i = 1; i < LOG; i++)
        for(int j = 1; j <= n; j++)
            fa[j][i] = fa[fa[j][i - 1]][i - 1];
}
void split(ll m) {
    int max_pos = log2(m) + 1;
    for(int i = 0; i < max_pos; i++)
        if(m & (1LL << i))
            res.push_back(i);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> m;
    for(int i = 1; i <= n; i++) cin >> dist[i];
    preprocess();
    split(m);
    for(int i = 1; i <= n; i++) {
        int ans = i;
        for(int j = 0; j < res.size(); j++)
            ans = fa[ans][res[j]];
        cout << ans << ' ';
    }
    return 0;
}
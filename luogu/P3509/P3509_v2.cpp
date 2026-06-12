#include <bits/stdc++.h>
#define N 1000010
#define LOG 61
typedef long long ll;
using namespace std;
int n, k;
ll m;
ll dist[N];
int ans[N], fa[N], fa_tmp[N];
void preprocess() {
    int l = 1, r = k + 1;
    for(int i = 1; i <= n; i++) {
        while(r + 1 <= n && dist[r + 1] - dist[i] < dist[i] - dist[l]) {
            l++;
            r++;
        }
        if(dist[i] - dist[l] >= dist[r] - dist[i])
            fa[i] = l;
        else
            fa[i] = r;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> m;
    for(int i = 1; i <= n; i++)
        cin >> dist[i];
    preprocess();
    for(int i = 1; i <= n; i++) 
        ans[i] = i;
    while(m > 0) {
        if(m & 1)
            for(int i = 1; i <= n; i++)
                ans[i] = fa[ans[i]];
        for(int i = 1; i <= n; i++) 
            fa_tmp[i] = fa[i];
        for(int i = 1; i <= n; i++)
            fa[i] = fa_tmp[fa_tmp[i]];
        m >>= 1;
    }
    for(int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    return 0;
}
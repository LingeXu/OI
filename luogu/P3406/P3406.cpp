#include <bits/stdc++.h>
#define N 100010
#define M 100010
typedef long long ll;
using namespace std;
int n, m;
ll to_visit[M], d[N], ti[N];
int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> to_visit[i];
        if(i != 1) {
            d[min(to_visit[i - 1], to_visit[i])]++;
            d[max(to_visit[i - 1], to_visit[i])]--;
        }
    }
    for(int i = 1; i < n; i++) 
        ti[i] = ti[i - 1] + d[i];
    ll ans = 0;
    for(int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        ans += 1LL * min(a * ti[i], c + b * ti[i]);
    }
    cout << ans;
    return 0;
}
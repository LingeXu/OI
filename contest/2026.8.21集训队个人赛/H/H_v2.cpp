#include <bits/stdc++.h>
using namespace std;
int n, q;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    map<int, int> pos_a, pos_b;                
    for(int i = 1; i <= n; i++)
        if(!pos_a.count(a[i]))  pos_a[a[i]] = i;
    for(int i = 1; i <= n; i++)
        if(!pos_b.count(b[i]))  pos_b[b[i]] = i;
    const int INF = 1e9;
    vector<int> need_a(n + 1), need_b(n + 1);
    for(int i = 1; i <= n; i++) {
        need_a[i] = need_a[i - 1];
        if(pos_a[a[i]] == i)                    
            need_a[i] = max(need_a[i], pos_b.count(a[i]) ? pos_b[a[i]] : INF);
    }
    for(int i = 1; i <= n; i++) {
        need_b[i] = need_b[i - 1];
        if(pos_b[b[i]] == i)
            need_b[i] = max(need_b[i], pos_a.count(b[i]) ? pos_a[b[i]] : INF);
    }
    cin >> q;
    while(q--) {
        int x, y;
        cin >> x >> y;
        cout << (need_a[x] <= y && need_b[y] <= x ? "Yes" : "No") << '\n';
    }
    return 0;
}

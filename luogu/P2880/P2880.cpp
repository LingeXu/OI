#include <bits/stdc++.h>
#define N 50050
#define Q 180018
using namespace std;
int n, q;
int h[N], a[Q], b[Q], max_h[Q], min_h[Q];
deque<int> dq_max, dq_min;
struct range {
    int l, r;
}r[Q];
bool cmp(range a, range b) {
    return a.l < b.l || (a.l == b.l && a.r < b.r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> h[i];
    for(int i = 1; i <= q; i ++)
        cin >> r[i].l >> r[i].r;
    sort(r + 1, r + q + 1, cmp);
    for(int i = 1; i <= q; i++) {
        int Left = r[i].l, Right = r[i].r;
        for(int j = (!dq_max.empty() ? max(dq_max.back(), Left) : Left); j <= Right; j++) {
            while(!dq_max.empty() && dq_max.front() < Left)
                dq_max.pop_front();
            while(!dq_max.empty() && h[dq_max.back()] < h[j])
                dq_max.pop_back();
            dq_max.push_back(j);
        }
        max_h[i] = h[dq_max.front()];
    }
    for(int i = 1; i <= q; i++) {
        int Left = r[i].l, Right = r[i].r;
        for(int j = (!dq_max.empty() ? max(dq_max.back(), Left) : Left); j <= Right; j++) {
            while(!dq_min.empty() && dq_min.front() < Left)
                dq_min.pop_front();
            while(!dq_min.empty() && h[dq_min.back()] > h[j])
                dq_min.pop_back();
            dq_min.push_back(j);
        }
        min_h[i] = h[dq_min.front()];
    }
    
    for(int i = 1; i <= q; i++) {
        cout << max_h[i] << ' ' << min_h[i] << '\n';
        cout << max_h[i] - min_h[i] << '\n';
    }

    return 0;
}
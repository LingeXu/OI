#include <bits/stdc++.h>
#define N 200020
typedef long long ll;
using namespace std;
int n, ans = 0;
ll sum = 0;
struct module {
    int w, s, t;
}m[N];
priority_queue<int, vector<int>, greater<int> > pq;
bool cmp(module a, module b) {
    return a.t < b.t;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) 
        cin >> m[i].w >> m[i].s >> m[i].t;
    sort(m, m + n, cmp);
    for(int i = 0; i < n; i++) {
        sum += (m[i].s - m[i].w);
        if(m[i].s - m[i].w >= 0) 
            continue;
        pq.push(m[i].s - m[i].w);
        if(sum < 0) {
            ans++;
            sum -= pq.top();
            pq.pop();
        }
    }
    cout << ans;
    return 0;
}
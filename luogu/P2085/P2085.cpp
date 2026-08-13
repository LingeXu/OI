#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, m;
priority_queue<ll, vector<ll>, less<ll> > pq;
vector<ll> ans;
ll GetAns(int a, int b, int c, int x) {
    return 1LL * (a * x * x + b * x + c);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        for(int j = 1; j <= m; j++) {
            if(i == 1)  pq.push(GetAns(a, b, c, j));
            else {
                ll val = GetAns(a, b, c, j);
                if(val >= pq.top()) break;
                else {
                    pq.pop();
                    pq.push(val);
                }
            }
        }
    }
    while(!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }
    for(int i = (int)ans.size() - 1; i >= 0; i--)
        cout << ans[i] << ' ';
    return 0;
}
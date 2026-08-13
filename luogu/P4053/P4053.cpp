#include <bits/stdc++.h>
#define N 150010
typedef long long ll;
using namespace std;
int n;
ll ans = 0;
struct building {
    int t1, t2;
} b[N];
priority_queue<int, vector<int>, less<int> > pq;
bool cmp (building x, building y) {
    return x.t2 < y.t2 || (x.t2 == y.t2 && x.t1 < y.t1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)  cin >> b[i].t1 >> b[i].t2;
    sort(b, b + n, cmp);
    ll ti = 0;
    for(int i = 0; i < n; i++) {
        ti += 1LL * b[i].t1;
        pq.push(b[i].t1);
        if(ti < b[i].t2) 
            continue;
        else {
            ti -= 1LL * pq.top();
            pq.pop();
        }
    }
    cout << (int)pq.size();
    return 0;
}
#include <bits/stdc++.h>
#define N 50050
typedef long long ll;
using namespace std;
int n, type;
struct cows {
    ll x, variety;
}c[N];
bool cmp(cows a, cows b) {
    return a.x < b.x;
}
int main() {
    cin >> n;
    set<int> s;
    for(int i = 1; i <= n; i++) {
        cin >> c[i].x >> c[i].variety;
        s.insert(c[i].variety);
    }
    type = s.size();
    sort(c + 1, c + n, cmp);
    ll ans = c[n].x;
    int start = 1;
    while(start <= n - type + 1) {
        set<int> record;
        for(int end = start + type - 1; end <= n; end++) {
            for(int now = start; now <= end; now ++) {
                record.insert(c[now].variety);
                if(record.size() == type)
                    ans = min(ans, c[end].x - c[start].x);
            }
        }
        start++;
    }
    cout << ans;
    return 0;
}
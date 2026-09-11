#include <bits/stdc++.h>
#define N 100010
#define MOD 998244353
typedef long long ll;
using namespace std;
int n, q;
string s, pat;
int a[N];
struct pre {
    ll val;
    int idx;
} prefix[N];
bool cmp(pre a, pre b) {
    return a.val < b.val;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q >> s;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        prefix[i].val = prefix[i - 1].val + a[i];
    }
    sort(prefix + 1, prefix + 1 + n, cmp);
    for(int i = 1; i <= q; i++) {
        cin >> pat;
        queue<int> q;
        int pos = 0;
        while(pos != -1) {
            pos = s.find(pos, pat);
            if(pos != -1)
                q.push(pos);
        }
        while(!q.empty()) {
            int x = q.pop();
            for(int j = 0; j < )
        }
    }
    return 0;
}
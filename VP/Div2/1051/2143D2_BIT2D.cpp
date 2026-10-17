#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
int t, n;


struct BIT2D {
    int sz;
    vector< vector<int> > val;
    BIT2D(int n) : sz(n + 1), val(n + 2, vector<int>(n + 2)) {}
    void add(int x, int y, int v) {
        for(int i = x + 1; i <= sz; i += i & -i)
            for(int j = y + 1; j <= sz; j += j & -j)
                val[i][j] = (val[i][j] + v) % MOD;
    }
    int sum(int x, int y) {
        int s = 0;
        for(int i = x + 1; i > 0; i -= i & -i)
            for(int j = y + 1; j > 0; j -= j & -j)
                s = (s + val[i][j]) % MOD;
        return s;
    }
};

void solve() {
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i];

    vector<int> vals = a;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int m = vals.size();

    BIT2D f(m + 1);                    
    f.add(0, 0, 1);
    for(int i = 0; i < n; i++) {
        int x = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin() + 1;
       
        for(int j = 0; j <= x; j++) {
            int w = (f.sum(x, j) - f.sum(x, j - 1) + MOD) % MOD; 
            f.add(x, j, w);
        }
        
        for(int j = x + 1; j <= m; j++) {
            int w = (f.sum(j, x) - f.sum(j - 1, x) + MOD) % MOD;  
            f.add(j, x, w);
        }
    }
    cout << f.sum(m, m) << '\n';      
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}

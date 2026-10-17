#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> ans;
int x;


void dfs(int n, int l, int r, int already) {
    if (n <= 0) return;                 
    if ((int)ans.size() >= x) return;   

    if (l == r) {
        for (int i = 0; i < n; i++)
            ans.push_back(l);
        return;
    }

    int mid = l + (r - l) / 2;
    cout << "? " << mid << endl;
    int resp;
    cin >> resp;
    int left_cnt = resp - already;      

    dfs(left_cnt, l, mid, already);
    dfs(n - left_cnt, mid + 1, r, already + left_cnt);
}

signed main() {
    cin >> x;
    dfs(x, 0, (int)1e18, 0);
    sort(ans.begin(), ans.end());
    cout << "! ";
    for (int i = 0; i < (int)ans.size(); i++) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << endl;
}

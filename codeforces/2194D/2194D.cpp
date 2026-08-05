#include <bits/stdc++.h>
using namespace std;
int t, n, m, cnt, aim;
vector< vector<int> > a;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--) {
        a.clear();
        cin >> n >> m;
        cnt = 0;
        vector<int> ones(n);
        for(int i = 1; i <= n; i++) {
            vector<int> row;
            for(int j = 1; j <= m; j++) {
                int num;
                cin >> num;
                if(num == 1) {
                    cnt++;
                    ones[i - 1]++;
                }
                row.push_back(num);
            }
            a.push_back(row);
        }
        if(cnt == 0) {
            cout << 0 << '\n';
            for(int i = 1; i <= n; i++)
                cout << 'D';
            for(int i = 1; i <= m; i++)
                cout << 'R';
            cout << '\n';
            continue;
        }
        aim = cnt >> 1;
        cout << 1LL * aim * (cnt - aim) << '\n';
        string s;
        int row_idx = 1, now = 0;
        while(row_idx <= n && now + ones[row_idx - 1] <= aim) {
            s += 'D';
            now += ones[row_idx - 1];
            row_idx++;
        }
        int excess = now + ones[row_idx - 1] - aim;
        for(int i = 1; i <= m; i++) {
            excess -= a[row_idx - 1][i - 1];
            s += 'R';
            if(excess == 0) {
                s += 'D';
                for(int j = i + 1; j <= m; j++)
                    s += 'R';
                break;
            }
        }
        while(s.size() < n + m)
            s += 'D';
        cout << s << '\n';
    }
    return 0;
}
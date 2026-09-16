#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector< pair<int, int> > record;
        for(int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if(i != x) 
                record.push_back(make_pair(i, x));
        }
        bool ok = true;
        for(int i = 0; i < (int)record.size(); i++) {
            int l = i, r = (int)record.size() - 1 - i;
            if(record[l].first == record[r].second && record[l].second == record[r].first)  continue;
            else {
                ok = false;
                break;
            }
        }
        if(ok)  cout << "YES\n";
        else {
            cout << "NO\n";
        }
    }
    return 0;
}
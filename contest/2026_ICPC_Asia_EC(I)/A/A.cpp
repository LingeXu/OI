#include <bits/stdc++.h>
using namespace std;
int t, n;
struct op {
    char c;
    int x;
};
void solve() {
    cin >> n;
    vector<op> record(n);
    vector< pair<int, int> > occ;
    vector<int> early(n);
    for(int i = 0; i < n; i++) {
        cin >> record[i].c >> record[i].x;
        occ.push_back(make_pair(record[i].x, i));
    }
    sort(occ.begin(), occ.end());
    for(auto it = occ.begin(); it != occ.end();) {
        auto it1 = upper_bound(occ.begin(), occ.end(), make_pair(it->first, 0x3f3f3f3f));
        for(auto it2 = it; it2 != it1; ) {
            while(it2 != it1 && record[it2->second].c != '+')
                it2++;
            if(it2 == it1)  break;  
            early[it2->second] = it2->second;
            auto it3 = next(it2);
            while(it3 != it1 && record[it3->second].c == 'T') {
                early[it2->second] = it3->second;
                it3++;
            }
            it2 = it3;
        }
        it = it1;
    }
    string ans;
    stack<int> s;
    for(int i = 0; i < n; i++) {
        while(!s.empty() && early[s.top()] < i) {
            s.pop();
            ans += '-';
        }
        if(record[i].c == '+') {
            ans += '+';
            s.push(i);
        }
        else    ans += '?';
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)  solve();
    return 0;
}
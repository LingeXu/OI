#include <bits/stdc++.h>
using namespace std;
int n;
void solve() {
    cin >> n;
    vector<int> exist(2 * n + 1, 0);
    vector< pair<int, int> > a;
    for(int i = 0; i <= 2 * n; i++) {
        if(exist[i] == 1)   break;
        a.push_back(make_pair(i, i ^ n));
        exist[i] = 1;
        exist[i ^ n] = 1;
    }
    cout << 4 * (int)a.size() - 1 << '\n';
    int pre = 0;
    vector<int> ans;
    for(auto &x : a) {
        //cout << "x.first = " << x.first << ", x.second = " << x.second << '\n';
        if(x.first == 0)     cout << (x.first ^ x.second) << ' ' << 0 << ' ' << (x.first ^ x.second) << ' ';
        else    cout << (pre ^ x.first) << ' ' << (x.first ^ x.second) << ' ' << 0 << ' ' << (x.first ^ x.second) << ' ';
        pre = x.first;
    }
    cout << '\n';
}
int main() {
    int t;
    cin >> t;
    while(t--)  solve();
    return 0;
}
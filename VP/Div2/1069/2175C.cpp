#include <bits/stdc++.h>
using namespace std;
int n;
string s, t;
void solve() {
    cin >> s >> t;
    unordered_map<char, int> mp1, mp2;
    for(char c : s)
        mp1[c]++;
    for(char c : t)
        mp2[c]++;
    for(auto &[c, cnt] : mp1) {
        if(mp2[c] < cnt) {
            cout << "Impossible\n";
            return;
        }
        else    mp2[c] -= cnt;
    }
    string to_insert;
    for(auto &[c, cnt] : mp2)
        for(int i = 0; i < cnt; i++)
            to_insert.push_back(c);
    sort(to_insert.begin(), to_insert.end());

   //cout << "to_insert = " << to_insert << '\n';
   
    string ans = s;
    int pre = 0;
    for(char c : ans) {
        auto it = lower_bound(to_insert.begin() + pre, to_insert.end(), c);
        int pos = it - to_insert.begin();
        to_insert.insert(to_insert.begin() + pos, c);
        pre = pos + 1;
    }
    cout << to_insert << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while(n--)  solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int t;
string s;
void solve() {
    cin >> s;
    int n = (int)s.size();
    vector<int> pos;
    for(int i = 0; i < n; i++) 
        if(i == 0 || s[i] != s[i - 1])
            pos.push_back(i);
    int m = (int)pos.size();
    deque<int> dq;
    dq.push_back(m - 1);
    for(int i = m - 2; i >= 0; i--) {
        if(s[pos[i]] > s[pos[i + 1]])
            dq.push_front(i);
        else    dq.push_back(i);
    }
    int need = (n + 1) / 2;
    for(int i : dq) {
        int num = (i + 1 < m ? pos[i + 1] : n) - pos[i];
        if(need > num)  need -= num;
        else {
            cout << s.substr(0, pos[i]) + s.substr(pos[i] + 1) << '\n';
            return;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)  solve();
    return 0;
}
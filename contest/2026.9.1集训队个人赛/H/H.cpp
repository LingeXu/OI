#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    
    priority_queue<string, vector<string>, greater<string>> pq;
    for(int i = 0; i < n; i++) {
        pq.push(s.substr(0, i) + s.substr(i + 1));
    }
    
    int mid = (n - 1) / 2;
    while(mid--) pq.pop();
    cout << pq.top() << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
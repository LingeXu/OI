#include <bits/stdc++.h>
using namespace std;
int n, m;
deque< pair<int, int> > dq;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        while(!dq.empty() && dq.back().first > x) dq.pop_back();
        dq.push_back({x, i});
        if(i < m)   continue;
        if(i >= m) {
            while(dq.front().second < i - m + 1)
                dq.pop_front(); 
            cout << dq.front().first << '\n';
        }
    }
    return 0;
}
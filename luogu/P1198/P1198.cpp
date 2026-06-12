#include <bits/stdc++.h>
using namespace std;
int m, d, t = 0, cnt = 0;
stack<int> s;
deque<int> dq;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> d;
    for(int i = 1; i <= m; i++) {
        char op;
        int x;
        cin >> op >> x;

        if(op == 'A')  {
            cnt = 0;
            while(!s.empty() && (x + t) % d > s.top()) { 
                s.pop();
                cnt++;
            }
            s.push((x + t) % d);
        }
        else if(op == 'Q') {
            if(cnt < x) {
                t = s.top();
                cout << t << '\n';
            }
            else {
                int y = s.top();
                s.pop();
                t = s.top();
                cout << t << '\n';
                s.push(y);
            }
        }
    }
    return 0;
}
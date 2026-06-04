#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
stack<int> s;
int main() {
    int n;
    ll ans = 0;
    cin >> n;
    for(int i = 1;  i <= n; i++) {
        int x;
        cin >> x;
        while(!s.empty() && s.top() <= x) 
            s.pop();
        ans += s.size();
        s.push(x);
    }
    cout << ans;
    return 0;
}
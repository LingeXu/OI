#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vector<int> chars;
    chars.reserve(n);
    for (char c : s)
        chars.push_back(c - 'a');
    sort(chars.begin(), chars.end());
    int ans = 0;
    for (int i = 0; i < n; i += 2) 
        ans += chars[i + 1] - chars[i];
    cout << ans;
    return 0;
}
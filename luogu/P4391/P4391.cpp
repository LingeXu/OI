#include <bits/stdc++.h>
using namespace std;
int l;
string s;
int init(const string& s) {
    int n = s.size();
    vector<int> next(n + 1, 0);
    next[0] = -1;
    int i = 0, j = -1;
    while(i < n) {
        if(j == -1 || s[i] == s[j]) 
            next[++i] = ++j;
        else    j = next[j];
    }
    return next[n];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> l >> s;
    cout << s.size() - init(s);
    return 0;
}
#include <bits/stdc++.h>
#define N 100010
using namespace std;
int n;
int h[N], s[N], idx[N];
map<int, int> mp;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> h[i];
    int top = 0;
    for(int i = 1; i <= n; i++) {
        while(top > 0 && s[top] < h[i]) {
            mp[idx[top]] = i;
            top--;
        }
        s[++top] = h[i];
        idx[top] = i;
    }
    for(int i = 1; i <= n; i++)
        cout << mp[i] << '\n';
    return 0;
}
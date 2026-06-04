#include <bits/stdc++.h>
#define N 250005
using namespace std;
int n;
int s[N];
int main() {
    cin >> n;
    int top = 0, ans = n;
    for(int i = 1; i <= n; i++) {
        int w, h;
        cin >> w >> h;
        while(top > 0 && s[top] >= h) {
            if(s[top] == h)
                ans--;
            top--;
        }
        s[++top] = h;
    }
    cout << ans;
    return 0;
}
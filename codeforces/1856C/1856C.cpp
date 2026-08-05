#include <bits/stdc++.h>
#define N 1010
#define K 100000010
using namespace std;
int t, n, k, max_ele;
vector<int> a;
bool check(int x) {
    if(x <= max_ele)    return true;
    for(int i = 0; i < n - 1; i++) {
        int op = 0;
        int j = i;
        while(j < n - 1 && a[j] < x - (j - i)) {
            op += x - (j - i) - a[j];
            if(op > k)  break;
            j++;
        }
        if(j < n - 1 && op <= k)
            return true;
        if(j == n - 1 && a[n - 1] >= x - (n - 1 - i) && op <= k)
            return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        a.clear();
        cin >> n >> k;
        max_ele = 0;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.push_back(x);
            max_ele = max(max_ele, x);
        }
        int Left = max_ele, Right = max_ele + k, ans = -1;
        while(Left <= Right) {
            int Mid = Left + (Right - Left) / 2;
            if(check(Mid)) {
                ans = Mid;
                Left = Mid + 1;
            }
            else    Right = Mid - 1;
        }
        cout << ans << '\n';
    }
    return 0;
}
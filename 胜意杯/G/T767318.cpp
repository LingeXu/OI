#include <bits/stdc++.h>
#define N 200020
using namespace std;
int n, k, max_ans = -1e9 - 10, min_ans = 1e9 + 10;
int a[N], pre_max[N], pre_min[N], suf_max[N], suf_min[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    pre_max[0] = -1e9 - 10;
    pre_min[0] = 1e9 + 10;
    for(int i = 1; i <= n; i++) {
        pre_max[i] = max(pre_max[i - 1], a[i]);
        pre_min[i] = min(pre_min[i - 1], a[i]);
    }
    suf_max[n+1] = -1e9 - 10;
    suf_min[n+1] = 1e9 + 10;
    for(int i = n; i >= 1; i--) {
        suf_max[i] = max(suf_max[i + 1], a[i]);
        suf_min[i] = min(suf_min[i + 1], a[i]);
    }
    
    for(int i = 1; i <= n - k + 1; i++) {
        int left_max = pre_max[i - 1];
        int right_max = suf_max[i + k];
        int outside_max = max(left_max, right_max);
        int left_min = pre_min[i - 1];
        int right_min = suf_min[i + k];
        int outside_min = min(left_min, right_min);
        if(max_ans < outside_max - outside_min)
            max_ans = outside_max - outside_min;
        if(min_ans > outside_max - outside_min)
            min_ans = outside_max - outside_min;
    }
    cout << max_ans << ' ' << min_ans << '\n';    
    return 0;
}
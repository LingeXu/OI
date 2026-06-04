#include <bits/stdc++.h>
#define N 1000010
using namespace std;
int T;
int main() {
    cin >> T;
    while(T > 0) {
        int n;
        cin >> n;
        vector<int> a(n);
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        int left = 0, ans = 0;
        for(int right = 0; right < n; right++) {
            if(mp.count(a[right])) 
                left = max(left, mp[a[right]] + 1);
            mp[a[right]] = right;
            ans = max(ans, right - left + 1);
        }
        cout << ans << '\n';
        T--;
    }
    return 0;
}
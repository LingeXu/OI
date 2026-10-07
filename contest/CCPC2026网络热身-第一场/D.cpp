#include <bits/stdc++.h>
using namespace std;
#define int long long
int countOrdered(const vector<int> &a) {
    int n = a.size();
    vector<int> rec, st;
    int res = 0;
    for (int i = 0; i < n; i++) {
        while (!rec.empty() && a[rec.back()] < a[i]) rec.pop_back();
        rec.push_back(i);
        while (!st.empty() && a[st.back()] >= a[i]) st.pop_back();
        int p = st.empty() ? -1 : st.back();  
        st.push_back(i);
        res += (int)(rec.end() - lower_bound(rec.begin(), rec.end(), p + 1));
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int c1 = countOrdered(a);  
    reverse(a.begin(), a.end());
    int c2 = countOrdered(a); 
    reverse(a.begin(), a.end());
    cout << c1 + c2 - n  << '\n';
    return 0;
}

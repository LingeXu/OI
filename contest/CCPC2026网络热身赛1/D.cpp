#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<int> a;
int cnt(vector<int> &a) {
    int res = 0;
    stack< pair<int, int> > st;
    vector<int> pre_bigger(n, -1);
    for(int i = 0; i < n; i++) {
        while(!st.empty() && st.top().second < a[i])   st.pop();
        if(!st.empty())
            pre_bigger[i] = st.top().first;
        else    pre_bigger[i] = -1;
        st.push(make_pair(i, a[i]));
    }

    /*for(int i = 0; i < n; i++)
        cout << "i = " << i << ", pre_bigger = " << pre_bigger[i] << '\n';*/
    
    vector< pair<int, int> > s;
    for(int i = 0; i < n; i++) {
        if(!s.empty() && a[i] > s.back().second) {
            int pos = upper_bound(s.begin(), s.end(), make_pair(pre_bigger[i], LLONG_MAX)) - s.begin();
            res += (int)s.size() - pos;
            s.push_back(make_pair(i, a[i]));
            continue;
        }
        while(!s.empty() && s.back().second > a[i]) 
            s.pop_back();
        s.push_back(make_pair(i, a[i]));
    }
    return res;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    int ans = cnt(a);
    reverse(a.begin(), a.end());
    cout << ans + cnt(a) + n;
    return 0;
}
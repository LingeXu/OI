#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n;
string s;
void solve() {
    cin >> n >> s;
    vector<int> two, zero, five, six, cnt(n + 5), diff(n + 5), diff_2(n + 5);
    for(int i = 0; i < n; i++) {
        if(s[i] == '2')
            two.push_back(i);
        if(s[i] == '0') 
            zero.push_back(i);
        if(s[i] == '5')
            five.push_back(i);
        if(s[i] == '6') 
            six.push_back(i);
    }
    int a = (int)two.size(), b = (int)zero.size(), c = (int)five.size(), d = (int)six.size();
    for(int i = 0; i < n; i++) {
        int pos1 = lower_bound(two.begin(), two.end(), i) - two.begin();
        if(pos1 == a) 
            continue;
        int pos2 = upper_bound(zero.begin(), zero.end(), two[pos1]) - zero.begin();
        if(pos2 == b) 
            continue;
        int pos3 = upper_bound(two.begin(), two.end(), zero[pos2]) - two.begin();
        if(pos3 == a) 
            continue;
        int pos4 = upper_bound(five.begin(), five.end(), two[pos3]) - five.begin();
        if(pos4 == c) 
            continue;
        int pos5 = upper_bound(six.begin(), six.end(), two[pos3]) - six.begin();
        if(pos5 == d) {
            diff_2[i] += n - five[pos4];
            diff_2[i + 1] -= (n - five[pos4]);
            diff_2[five[pos4] + 1]--;
            diff_2[n + 1]++;
            continue;
        }
        if(six[pos5] < five[pos4])
            continue;
        //cout << "pos1 = " << pos1 << ", pos2 = " << pos2 << ", pos3 = " << pos3 << ", pos4 = " << pos4 << ", pos5 = " << pos5 << '\n';
        diff_2[i] += six[pos5] - five[pos4];
        diff_2[i + 1] -= (six[pos5] - five[pos4]);
        diff_2[five[pos4] + 1]--;
        diff_2[six[pos5] + 1]++;
    }
    for(int i = 0; i < n; i++) {
        if(i == 0)  diff[i] = diff_2[i];
        else    diff[i] = diff[i - 1] + diff_2[i];
    }
    for(int i = 0; i < n; i++){
        if(i == 0)  cnt[i] = diff[i];
        else    cnt[i] = cnt[i - 1] + diff[i];
        cout << (i + 1) * (n - i) - cnt[i] << ' ';
    }
    cout << '\n';
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}
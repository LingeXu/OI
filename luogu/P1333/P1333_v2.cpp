#include <bits/stdc++.h>
#define N 500005
using namespace std;
int cnt = 0;
int fa[N], deg[N];
map<string, int> mp;
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void unite(int x, int y) {
    int rx = find(x), ry = find(y);
    if(rx != ry) {
        cnt--;
        fa[rx] = ry;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s1, s2;
    int idx = 0;
    while(cin >> s1 >> s2) {
        if(!mp[s1]) {
            cnt++;
            mp[s1] = ++idx;
            fa[idx] = idx;
        }
        deg[mp[s1]]++;
        if(!mp[s2]) {
            cnt++;
            mp[s2] = ++idx;
            fa[idx] = idx;
        }
        deg[mp[s2]]++;
        unite(mp[s1], mp[s2]);
    }
    if(idx == 0) {
        cout << "Possible";
        return 0;
    }
    if(cnt != 1) {
        cout << "Impossible";
        return 0;
    }
    int odd_deg_cnt = 0;
    for(int i = 1; i <= idx; i++)
        if(deg[i] & 1) 
            odd_deg_cnt++;
    cout << (odd_deg_cnt == 0 || odd_deg_cnt == 2 ? "Possible" : "Impossible");
    return 0;
}
#include <bits/stdc++.h>
#define N 200020
using namespace std;
int n;
bool valid[N];
struct people {
    int skill, pre, next;
    char gender;
} p[N];
struct pr {
    int delta, l, r;
    bool operator>(const pr& x1) const{
        return this->delta > x1.delta || (this->delta == x1.delta && this->l > x1.l);
    }
};
priority_queue<pr, vector<pr>, greater<pr> > pq;
vector< pair<int, int> > ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> p[i].gender;
    for(int i = 1; i <= n; i++)
        cin >> p[i].skill;
    for(int i = 1; i < n; i++) {
        p[i].pre = i - 1;
        p[i].next = i + 1;
        if(p[i].gender == p[i + 1].gender)  continue;
        int val = abs(p[i + 1].skill - p[i].skill);
        pq.push({val, i, i + 1});
    }
    p[n].pre = n - 1;
    p[n].next = n + 1;
    for(int i = 1; i <= n; i++)
        valid[i] = true;
    while(!pq.empty()) {
        pr x = pq.top();
        pq.pop();
        if(!valid[x.l] || !valid[x.r])  continue;
        valid[x.l] = valid[x.r] = false;
        p[p[x.l].pre].next = p[x.r].next;
        p[p[x.r].next].pre = p[x.l].pre;
        ans.push_back(make_pair(x.l, x.r));
        if(p[x.l].pre == 0 || p[x.r].next == n + 1 || p[p[x.l].pre].gender == p[p[x.r].next].gender)    continue;
        int val = abs(p[p[x.l].pre].skill - p[p[x.r].next].skill);
        pq.push({val, p[x.l].pre, p[x.r].next});
    }
    cout << (int)ans.size() << '\n';
    for(int i = 0; i < (int)ans.size(); i++)    cout << ans[i].first << ' ' << ans[i].second << '\n';
    return 0;
}
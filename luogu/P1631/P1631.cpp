#include <bits/stdc++.h>
#define N 100010
using namespace std;
int n;
int a[N], b[N];
priority_queue<int, vector<int>, less<int> > pq;
vector<int> ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)  cin >> a[i];
    for(int i = 0; i < n; i++)  cin >> b[i];
    //sort(a, a + n);
    //sort(b, b + n);
    for(int i = 0; i < n; i++)
        pq.push(a[0] + b[i]);
    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= n / (i + 1); j++) {
            if(a[i] + b[j] >= pq.top())  break;
            else {
                pq.pop();
                pq.push(a[i] + b[j]);
            }
        }
    }
    while(!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }
    for(int i = (int)ans.size() - 1; i >= 0; i--)   cout << ans[i] << ' ';
    return 0;
}
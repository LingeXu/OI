#include <bits/stdc++.h>
#define N 200020
#define M 200020
using namespace std;
int n, m, mid;
int a[N], u[M];
priority_queue<int, vector<int>, less<int> > pq1;
priority_queue<int, vector<int>, greater<int> > pq2;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)  cin >> a[i];
    for(int i = 1; i <= m; i++)  cin >> u[i];
    int ans = 0;
    for(int i = 1; i <= m; i++) {
        if(i == 1) {
            for(int j = 1; j <= u[1]; j++)  pq2.push(a[j]);
            mid = pq2.top();
            cout << mid << '\n';
            pq2.pop();
        }
        else {
            for(int j = u[i - 1] + 1; j <= u[i]; j++) {
                if(a[j] < mid)  pq1.push(a[j]);
                else    pq2.push(a[j]);
            }
            while((int)pq1.size() > i - 1) {
                pq2.push(mid);
                mid = pq1.top();
                pq1.pop();
            }
            while((int)pq2.size() > u[i] - i) {
                pq1.push(mid);
                mid = pq2.top();
                pq2.pop();
            } 
            cout << mid << '\n';
        }
    }
    return 0;
}
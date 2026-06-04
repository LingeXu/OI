#include <bits/stdc++.h>
#define N 2000020
using namespace std;
int n, k;
int a[N];
deque<int> dq;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++) {
        while(!dq.empty() && a[i] > a[dq.back()])
            dq.pop_back();
        dq.push_back(i);
        while(dq.front() < i - k + 1)
            dq.pop_front();
        if(i >= k)
            cout << a[dq.front()] << '\n';
    }
    return 0;
}
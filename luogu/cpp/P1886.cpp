#include <bits/stdc++.h>
#define N 1000010
using namespace std;
int n, k;
int a[N];
deque<int> dq_max, dq_min;
int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++) {
        while(!dq_min.empty() && dq_min.front() < i - k + 1)
            dq_min.pop_front();
        while(!dq_min.empty() && a[dq_min.back()] > a[i])
            dq_min.pop_back();
        dq_min.push_back(i);
        if(i >= k)
            cout << a[dq_min.front()] << ' ';
    }
    cout << '\n';
    for(int i = 1; i <= n; i++) {
        while(!dq_max.empty() && dq_max.front() < i - k + 1)
            dq_max.pop_front();
        while(!dq_max.empty() && a[dq_max.back()] < a[i])
            dq_max.pop_back();
        dq_max.push_back(i);
        if(i >= k)
            cout << a[dq_max.front()] << ' ';
    }
    return 0;
}
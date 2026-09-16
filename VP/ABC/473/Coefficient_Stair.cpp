#include <bits/stdc++.h>
using namespace std;
int n, k;
deque<int> dq;
void dfs(int pos, int remain) {
    if(remain < 0 || pos > n)  return;
    if(remain == 0) {
        for(int num : dq)
            cout << num << ' ';
        for(int i = pos; i <= n; i++)
            cout << 0 << ' ';
        cout << '\n';
        return;
    }
    if(pos > remain)    return;
    if(pos == n && remain % n == 0) {
        for(int i : dq)
            cout << num << ' ';
        cout << remain / n << '\n';
        return;
    }
    if(pos == n && remain % n != 0) 
        return;
    for(int i = 0; i <= remain / pos; i++) {
        dq.push_back(i);
        dfs(pos + 1, remain - i * pos);
        dq.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin >> n >> k;
    dfs(1, k);
    return 0;
}
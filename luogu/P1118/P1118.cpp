#include <bits/stdc++.h>
using namespace std;
int n, sum;
vector<int> ans;
bool dfs(int x, int layers) {
    if (layers == 1 && x <= n) {
        ans.push_back(x);
        return true;
    }
    for(int i = 1; i < x; i++)
        if(dfs(i, layers - 1) && dfs(x - i, layers - 1))
            return true;
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> sum;
    if(dfs(sum, n) )
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
    return 0;
}
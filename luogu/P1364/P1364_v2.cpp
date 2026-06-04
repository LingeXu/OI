#include<iostream>
#include<cstring>
#include<algorithm>
#define MAXN 110
#define INF 0x3f3f3f3f
using namespace std;
struct BinaryTreeNode {
    int val, left, right, father;
    BinaryTreeNode(int w = 0, int u = 0, int v = 0): val(w), left(u), right(v), father(0) {}
    //BinaryTreeNode(): val(0), left(0), right(0), father(0) {}
}btn[MAXN];
bool vis[MAXN];
int dfs(int pos, int dep) {
    if(pos == 0 || vis[pos])
        return 0;
    vis[pos] = true;
    //cout << "pos=" << pos << " dep=" << dep << " val=" << btn[pos].val << " sum=" << '\n';
    return dfs(btn[pos].left, dep + 1) + dfs(btn[pos].right, dep + 1) + dfs(btn[pos].father, dep + 1) + btn[pos].val * dep;
}
int main() {
    int n;
    cin >> n;
    int w, u, v;
    for(int i = 1; i <= n; i++) {
        cin >> w >> u >> v;
        btn[i] = BinaryTreeNode(w, u, v);
    }
    for(int i = 1; i <= n; i++) {
        int u = btn[i].left, v = btn[i].right;
        if(u != 0)
            btn[u].father = i;
        if(v != 0)
            btn[v].father = i;
    }
    int ans = INF;
    for(int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        ans = min(ans, dfs(i, 0));
    }
    cout << ans;
    return 0;
}

/*#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 110
#define INF 0x3f3f3f3f
using namespace std;

struct BinaryTreeNode {
    int val, left, right, father;
    BinaryTreeNode(int w = 0, int u = 0, int v = 0) 
        : val(w), left(u), right(v), father(0) {}
} btn[MAXN];

bool vis[MAXN];

int dfs(int pos, int dep) {
    if (pos == 0 || vis[pos]) return 0;
    vis[pos] = true;
    
    int leftSum = dfs(btn[pos].left, dep + 1);
    int rightSum = dfs(btn[pos].right, dep + 1);
    int fatherSum = dfs(btn[pos].father, dep + 1);
    int res = leftSum + rightSum + fatherSum + btn[pos].val * dep;
    
    cout << "pos=" << pos << " dep=" << dep << " val=" << btn[pos].val 
         << " left=" << leftSum << " right=" << rightSum 
         << " father=" << fatherSum << " res=" << res << '\n';
    return res;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int w, u, v;
        cin >> w >> u >> v;
        btn[i] = BinaryTreeNode(w, u, v);
        if (u != 0) btn[u].father = i;
        if (v != 0) btn[v].father = i;
    }
    
    cout << "=== Input data ===\n";
    for (int i = 1; i <= n; i++) {
        cout << i << ": val=" << btn[i].val 
             << " left=" << btn[i].left 
             << " right=" << btn[i].right 
             << " father=" << btn[i].father << '\n';
    }
    
    int ans = INF;
    for (int i = 1; i <= n; i++) {
        cout << "\n=== Root=" << i << " ===\n";
        memset(vis, 0, sizeof(vis));
        int cur = dfs(i, 0);
        cout << "sum=" << cur << '\n';
        ans = min(ans, cur);
    }
    cout << "ans=" << ans << '\n';
    
    return 0;
}*/

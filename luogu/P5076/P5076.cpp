#define LOCAL
#ifdef LOCAL
#define debug(x)    cout<<'['<<__LINE__<<']'<<" "<<#x<<" = "<<x;
#else
#define debug(x)
#endif
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<list>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<sstream>
#define Q 10010
#define INF 2147483647
using namespace std;
struct BinaryTreeNode {
    int val, rank, leftsize, rightsize;
    BinaryTreeNode *leftchild,*rightchild;
    BinaryTreeNode(int x):val(x), rank(0), leftsize(0), rightsize(0), leftchild(nullptr), rightchild(nullptr) {}
};
/*vector<BinaryTreeNode*> BinaryTree;
void BuildBinaryTree(int x) {
    BinaryTreeNode *finalnode = new BinaryTreeNode(x);
    BinaryTree.push_back(finalnode);
    int n = BinaryTree.size();
    if(n == 1) 
        return;  
    if(n & 0)
        BinaryTree[n/2-1]->leftchild = finalnode;
    else    BinaryTree[n/2-1]->rightchild = finalnode;
}
void FilterUp(BinaryTreeNode *finalnode) {
    int now = BinaryTree.size();
    if(now == 1)    return;
    while(finalnode->val < BinaryTree[now / 2 - 1]->val) {
        swap(finalnode->val, BinaryTree[now / 2 - 1]->val);
        now = now / 2 - 1;
    }
    
}*/
void BuildBinaryTree(int x, BinaryTreeNode *r){
    if(x < r->val) {
        r->leftsize++;
        if(r->leftchild == nullptr) {
            r->leftchild = new BinaryTreeNode(x);;
            return;
        }
        BuildBinaryTree(x, r->leftchild);
    }
    if(x > r->val) {
        r->rightsize++;
        if(r->rightchild == nullptr) {
            r->rightchild = new BinaryTreeNode(x);
            return;
        }
        BuildBinaryTree(x, r->rightchild); 
    }
}
void GetRank(int x, BinaryTreeNode *r) {
    int rank = 1;
    while(r) {
        if(r->val == x) {
            rank += r->leftsize;
            cout << rank << '\n';
            return;
        }
        if(r->val < x) {
            rank += (r->leftsize + 1);
            r = r->rightchild;
        }
        else 
            r = r->leftchild;
    }
    cout << rank << '\n';
    return;
}
void Inquire(int x, BinaryTreeNode *r){
    while(r) {
        if(x == r->leftsize + 1) {
            cout << r->val << '\n';
            return;
        }
        if(r->leftsize + 1 < x) {
            x -= (r->leftsize + 1);
            r = r->rightchild;     
        }
        else 
            r = r->leftchild;
    }
    return;
}
void GetPrecursor(int x, BinaryTreeNode *r) {
    int ans = -INF;
    while(r) {
        if(r->val < x) {
            ans = max(ans, r->val);
            r = r->rightchild;
        }
        else 
            r = r->leftchild;
    }
    cout << ans << '\n';
    return;
}
void GetSuccessor(int x, BinaryTreeNode *r) {
    int ans = INF;
    while(r) {
        if(r->val > x) {
            ans = min(ans, r->val);
            r = r->leftchild;
        }
        else
            r = r->rightchild;
    }
    cout << ans << '\n';
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    int op,x,op5_cnt=0;
    BinaryTreeNode *root = nullptr;
    for(int i = 1; i <= q; i++) {
        cin >> op >> x;
        if(op == 5) {
            if(++op5_cnt == 1) {
                root = new BinaryTreeNode(x);
                continue;
            }
            BuildBinaryTree(x, root);
        }
        if(op == 1) 
            GetRank(x, root);
        if(op == 2) 
            Inquire(x, root);
        if(op == 3)
            GetPrecursor(x, root);
        if(op == 4)
            GetSuccessor(x, root);
    }
    return 0;
}
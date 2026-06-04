#include<iostream>
#define MAXN 110
using namespace std;

struct BinaryTreeNode {
    int id, weight, leftweight, rightweight;
    BinaryTreeNode *leftchild, *rightchild;
    BinaryTreeNode(int i, int w, BinaryTreeNode *lc, BinaryTreeNode *rc): id(i), weight(w), leftweight(0), rightweight(0), leftchild(lc), rightchild(rc) {}
    BinaryTreeNode():  id(0), weight(0), leftweight(0), rightweight(0), leftchild(nullptr), rightchild(nullptr) {}
}btn[MAXN];

int GetSumWeight(BinaryTreeNode *r) {
    if(r == nullptr)
        return 0;
    return GetSumWeight(r->leftchild) + GetSumWeight(r->rightchild) + r->weight;
}

int n;
void GetWeight(BinaryTreeNode *r) {
    for(int i = 1; i <= n; i++) {
        btn[i].leftweight = GetSumWeight((btn+i)->leftchild);
        btn[i].rightweight = GetSumWeight((btn+i)->rightchild);
    }
}

int GetOriginalAns(BinaryTreeNode *r) {
    if(r == nullptr)
        return 0;
    return GetOriginalAns(r->leftchild) + GetOriginalAns(r->rightchild) + GetSumWeight(r->leftchild) +GetSumWeight(r->rightchild);
}

void FindNode(BinaryTreeNode *r) {
    int ans = GetOriginalAns(r), weight_sum = GetSumWeight(r);
    while(r) {
        if(r->leftweight > weight_sum / 2) {
            ans = ans - 2*r->leftweight + weight_sum ;
            r = r->leftchild;
        }
        else if(r->rightweight > weight_sum / 2) {
            ans = ans - 2*r->rightweight  + weight_sum;
            r = r->rightchild;
        }
        else    break;
    }
    cout << ans << '\n';
}
int main() {
    cin >> n;
    int w, u, v;
    for(int i = 1; i <= n; i++) {
        cin >> w >> u >> v;
        btn[i] = BinaryTreeNode(i, w, btn + u, btn + v);
        if(u == 0)
            btn[i].leftchild = nullptr;
        if(v == 0)
            btn[i].rightchild = nullptr;
    }
    BinaryTreeNode *root = btn + 1;
    GetWeight(root);
    FindNode(root);
    return 0;
}
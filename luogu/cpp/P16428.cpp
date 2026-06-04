#include <iostream>
#include <string>
#include <algorithm>
#define MAXN 300010
using namespace std;

int cnt = 0;
struct BinaryTreeNode {
    int val;
    string preo, ino, posto;
    BinaryTreeNode *leftchild, *rightchild;
} btn[MAXN];

string GetPreOrder(BinaryTreeNode *r) {
    if (r == nullptr) return "";
    string left = GetPreOrder(r->leftchild);
    string right = GetPreOrder(r->rightchild);
    r->preo = to_string(r->val);
    if (!left.empty()) r->preo += " " + left;
    if (!right.empty()) r->preo += " " + right;
    return r->preo;
}

string GetInOrder(BinaryTreeNode *r) {
    if (r == nullptr) return "";
    string left = GetInOrder(r->leftchild);
    string right = GetInOrder(r->rightchild);
    string inorder;
    if (!left.empty()) inorder += left + " ";
    inorder += to_string(r->val);
    if (!right.empty()) inorder += " " + right;
    return r->ino = inorder;
}

string GetPostOrder(BinaryTreeNode *r) {
    if (r == nullptr) return "";
    string left = GetPostOrder(r->leftchild);
    string right = GetPostOrder(r->rightchild);
    string postorder;
    if (!left.empty()) postorder += left + " ";
    if (!right.empty()) postorder += right + " ";
    postorder += to_string(r->val);
    return r->posto = postorder;
}

void CmpPreThenSwap(BinaryTreeNode *r, int k) {
    if (cnt >= k) return;
    if (r == nullptr || r->leftchild == nullptr || r->rightchild == nullptr) return;
    if (r->leftchild->preo > r->rightchild->preo) {
        swap(r->leftchild, r->rightchild);
        cnt++;
        GetPreOrder(r);
    }
}

void OpPreOrder(BinaryTreeNode *r, int k) {
    if (r == nullptr) return;
    CmpPreThenSwap(r, k);
    OpPreOrder(r->leftchild, k);
    OpPreOrder(r->rightchild, k);
}

void CmpInThenSwap(BinaryTreeNode *r, int k) {
    if (cnt >= k) return;
    if (r == nullptr || r->leftchild == nullptr || r->rightchild == nullptr) return;
    if (r->leftchild->ino > r->rightchild->ino) {
        swap(r->leftchild, r->rightchild);
        cnt++;
        GetInOrder(r);
    }
}

void OpInOrder(BinaryTreeNode *r, int k) {
    if (r == nullptr) return;
    CmpInThenSwap(r, k);
    OpInOrder(r->leftchild, k);
    OpInOrder(r->rightchild, k);
}

void CmpPostThenSwap(BinaryTreeNode *r, int k) {
    if (cnt >= k) return;
    if (r == nullptr || r->leftchild == nullptr || r->rightchild == nullptr) return;
    if (r->leftchild->posto > r->rightchild->posto) {
        swap(r->leftchild, r->rightchild);
        cnt++;
        GetPostOrder(r);
    }
}

void OpPostOrder(BinaryTreeNode *r, int k) {
    if (r == nullptr) return;
    CmpPostThenSwap(r, k);
    OpPostOrder(r->leftchild, k);
    OpPostOrder(r->rightchild, k);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    char c;
    int n, root, k;
    cin >> c >> n >> root >> k;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        btn[i].val = i;
        btn[i].leftchild = (l == 0) ? nullptr : &btn[l];
        btn[i].rightchild = (r == 0) ? nullptr : &btn[r];
    }

    BinaryTreeNode *rt = &btn[root];
    if (c == 'A'){
        GetPreOrder(rt);
        OpPreOrder(rt, k);
        GetPreOrder(rt);
        cout << rt->preo << '\n';
    }
    else if (c == 'B') {
        GetInOrder(rt);
        OpInOrder(rt, k);
        GetInOrder(rt);
        cout << rt->ino << '\n';
    }
    else if (c == 'C'){
        GetPostOrder(rt);
        OpPostOrder(rt, k);
        GetPostOrder(rt);
        cout << rt->posto << '\n';
    }
    return 0;
}
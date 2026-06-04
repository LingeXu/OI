#include<iostream>
using namespace std;
struct BinaryTreeNode {
    char val;
    BinaryTreeNode *leftchild, *rightchild;
    BinaryTreeNode(char c = ' ', BinaryTreeNode *lc = nullptr, BinaryTreeNode *rc = nullptr): val(c), leftchild(lc), rightchild(rc) {}
};

BinaryTreeNode* BuildTree(string io, string po) {
    BinaryTreeNode *r = new BinaryTreeNode;
    if(po.empty())  return r;
    r->val = po.back();
    cout << r->val;
    int pos;
    for(int i = 0; i < io.size(); i++)
        if(io[i] == po.back())
            pos = i;
    r->leftchild = BuildTree(io.substr(0, pos), po.substr(0, pos));
    r->rightchild = BuildTree(io.substr(pos + 1), po.substr(pos, io.size() - pos - 1));
    return r;
}
int main() {
    string inorder, postorder;
    cin >> inorder >> postorder;
    BuildTree(inorder, postorder);
    return 0;
}
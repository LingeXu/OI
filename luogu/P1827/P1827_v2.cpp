#define LOCAL
#ifdef LOCAL
#define debug(x)    cout<<'['<<__LINE__<<"]"<<" "<<#x<<" "<<" = "<<x;
#else
#define debug(x)
#endif
#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct BinaryTreeNode {
    char val;
    BinaryTreeNode *leftchild, *rightchild;
    BinaryTreeNode(char c): val(c), leftchild(NULL), rightchild(NULL) {}
};
BinaryTreeNode* BuildTree(string io, string po){
    if(io.empty() || po.empty())
        return NULL;
    char rootval = po[0];
    int pos = (int)io.find(rootval);
    BinaryTreeNode *root = new BinaryTreeNode(rootval);
    string leftio = io.substr(0, pos), rightio = io.substr(pos + 1);
    string leftpo = po.substr(1, pos), rightpo = po.substr(pos + 1);
    root->leftchild = BuildTree(leftio, leftpo);
    root->rightchild = BuildTree(rightio, rightpo);
    return root;
}
void PostOrder(BinaryTreeNode *root){
    if(root == NULL)
        return;
    PostOrder(root->leftchild);
    PostOrder(root->rightchild);
    cout << root->val;
}
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string inorder, preorder;
    cin>>inorder>>preorder;
    PostOrder(BuildTree(inorder, preorder));
    return 0;
}
#include<iostream>
using namespace std;
struct BinaryTreeNode {
    char val;
    BinaryTreeNode *leftchild, *rightchild;
    BinaryTreeNode(char c = ' ', BinaryTreeNode *lc = nullptr, BinaryTreeNode *rc = nullptr): val(c), leftchild(lc), rightchild(rc) {}
};
BinaryTreeNode* BuildTree(string s) {
    BinaryTreeNode *r = new BinaryTreeNode;
    if(s == "0") {
        r->val = 'B';
        return r;
    }
    if(s == "1") {
        r->val = 'I';
        return r;
    }
    r->val = 'F';
    if(count(s.begin(), s.end(), '0') == 0)   r->val = 'I';
    if(count(s.begin(), s.end(), '1') == 0)   r->val = 'B';
    int pos = s.size()/2;
    r->leftchild = BuildTree(s.substr(0, pos));
    cout << r->leftchild->val;
    r->rightchild = BuildTree(s.substr(pos));
    cout << r->rightchild->val;
    return r;
}
int main() {
    int n;
    string s;
    cin >> n >> s;
    BuildTree(s);
    if(count(s.begin(), s.end(), '0') == 0)   cout << 'I';
    else if(count(s.begin(), s.end(), '1') == 0)   cout << 'B';
    else    cout << 'F';
    return 0;
}
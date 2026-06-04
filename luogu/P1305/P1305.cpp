#include<iostream>
#define MAXN 30
using namespace std;
struct BinaryTreeNode {
    char node, left, right;
}btn[MAXN];

void PreOrder(BinaryTreeNode *r) {
    cout << r->node;
    if(r->left != '*')
        PreOrder(&btn[r->left - 'a']);
    if(r->right != '*')
    PreOrder(&btn[r->right - 'a']);
}
int main() {
    int n;
    cin >> n;
    BinaryTreeNode *root;
    for(int i = 1; i <= n; i++) {
        char a, b, c;
        cin >> a >> b >> c;
        btn[a - 'a'].node = a;
        btn[a - 'a'].left = b;
        btn[a - 'a'].right = c;
        if(i == 1)
            root = &btn[a - 'a'];
    }
    PreOrder(root);
    return 0;
}
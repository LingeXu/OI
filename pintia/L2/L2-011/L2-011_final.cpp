#include<iostream>
#include<vector>
#include<queue>

#define N 31

using namespace std;

vector<int> inOrder(N),preOrder(N);

struct BinaryTreeNode{
    int val;
    BinaryTreeNode *leftchild,*rightchild;
}node[N]={-1,NULL,NULL};

BinaryTreeNode* build(int inL,int inR,int preL,int preR){
    if(inL>inR||preL>preR)    return NULL;

    BinaryTreeNode *root=new BinaryTreeNode;
    root->val=preOrder[preL];

    int k;
    for(int i=inL;i<=inR;i++){
        if(root->val==inOrder[i]){
            k=i;
            break;
        }
    }
        
    int leftsize=k-inL;
    root->leftchild=build(inL,k-1,preL+1,preL+leftsize);
    root->rightchild=build(k+1,inR,preL+leftsize+1,preR);

    return root;
}

void bfs(BinaryTreeNode *root){
    queue<BinaryTreeNode*> q;
    q.push(root);

    while(!q.empty()){
        BinaryTreeNode* x=q.front();
        q.pop();
        cout<<x->val;

        if(x->rightchild!=NULL)
            q.push(x->rightchild);
        if(x->leftchild!=NULL)
            q.push(x->leftchild);
        
        if(!q.empty())
            cout<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)    cin>>inOrder[i];
    for(int i=0;i<n;i++)    cin>>preOrder[i];

    BinaryTreeNode *root=build(0,n-1,0,n-1);
    bfs(root);
    return 0;
}
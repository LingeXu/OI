#include<iostream>
#include<vector>
#include<queue>

#define N 31

using namespace std;

vector<int> preOrder,inOrder;

struct BinaryTreeNode{
    int val;
    BinaryTreeNode* leftchild,*rightchild;
}node[N]={0,NULL,NULL};

BinaryTreeNode* build(vector<int> in,vector<int> pre){
    if(in.empty()||pre.empty())  return NULL;

    BinaryTreeNode *root=new BinaryTreeNode;
    root->val=pre[0];

    int k;
    for(int i=0;i<in.size();i++){
        if(in[i]==root->val){
            k=i;
            break;
        }
    }

    vector<int> in_left(in.begin(),in.begin()+k),in_right(in.begin()+k+1,in.end()),pre_left(pre.begin(),pre.begin()+k),pre_right(pre.begin()+k+1,pre.end());
    root->leftchild=build(in_left,pre_left);
    root->rightchild=build(in_right,pre_right);

    return root;

    /*if(k!=0)
        node[root].leftchild=&node[pre[1]];
    else   node[root].leftchild=NULL; 

    if(k+1<pre.size())
        node[root].rightchild=&node[pre[k+1]];
    else   node[root].rightchild=NULL; 

    vector<int> in_left,in_right,pre_left,pre_right;
    for(int i=0;i<k;i++){
        in_left.push_back(in[i]);
        pre_left.push_back(pre[i+1]);
    }
    for(int i=k+1;i<in.size();i++){
        in_right.push_back(in[i]);
        pre_right.push_back(pre[i]);
    }

    build(in_left,pre_left);
    build(in_right,pre_right);*/ 
}

void bfs(int rootval){
    queue<int> q;
    q.push(rootval);

    while(!q.empty()){
        int x=q.front();
        cout<<x<<" ";
        q.pop();

        if(node[x].leftchild!=NULL)
            q.push(node[x].leftchild->val);

        if(node[x].rightchild!=NULL)
            q.push(node[x].rightchild->val);
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        inOrder.push_back(x);
    }
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        preOrder.push_back(x);
    }

    BinaryTreeNode *root=build(inOrder,preOrder);
    bfs(root->val);
    return 0;
}
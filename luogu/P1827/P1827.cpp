#include<iostream>
#define N 30
using namespace std;
void PostOrder(string io,string po){
    char root=po[0];
    int position=io.find(root);
    if(position!=0)
        PostOrder(io.substr(0,position),po.substr(1,position));
    if(position!=io.size()-1)
        PostOrder(io.substr(position+1),po.substr(position+1));
    cout<<root;
}
int main(){
    string inorder,preorder;
    cin>>inorder>>preorder;
    PostOrder(inorder,preorder);
    return 0;
}
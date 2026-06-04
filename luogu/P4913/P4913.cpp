#include<iostream>
#include<iomanip>
#define N 1000010
using namespace std;
struct BinaryTreeNode{
    int id;
    BinaryTreeNode *FirstChild,*SecondChild;
}b[N];
int GetHeight(BinaryTreeNode *r){
    if(r==NULL)
        return 0;
    return max(GetHeight(r->FirstChild),GetHeight(r->SecondChild))+1;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int fc,sc;
        cin>>fc>>sc;
        b[i].id=i;
        b[i].FirstChild=b+fc;
        b[i].SecondChild=b+sc;
        if(fc==0)
            b[i].FirstChild=NULL;
        if(sc==0)
            b[i].SecondChild=NULL;
    }
    cout<<GetHeight(b+1);
    return 0;
}
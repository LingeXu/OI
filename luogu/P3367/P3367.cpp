#include<iostream>
#define N 200010
using namespace std;
int fa[N];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void unite(int x,int y){
    int rx=find(x),ry=find(y);
    if(rx!=ry)  fa[rx]=ry;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)   fa[i]=i;
    for(int i=1;i<=m;i++){
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1)
            unite(x,y);
        else if(op==2){
            if(find(x)==find(y))
                cout<<'Y'<<'\n';
            else
                cout<<'N'<<'\n';
        }
    }
    return 0;
}
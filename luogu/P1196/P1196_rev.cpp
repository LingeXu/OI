#include<iostream>

#define T 30001
using namespace std;

int t;
int fa[T],ranking[T],length[T];

int find(int x){
    if(fa[x]==x)    return x;
    else
    {
        int root=find(fa[x]);
        ranking[x]+=ranking[fa[x]];
        return fa[x]=root;
    }
}

void unite(int x,int y){
    int rx=find(x),ry=find(y);
    
    if(rx!=ry)
    {
        ranking[rx]+=length[ry];
        length[ry]+=length[rx];
        fa[rx]=ry;
    }
}


int main(){
    scanf("%d",&t);

    for(int i=1;i<=30000;i++)   fa[i]=i;
    for(int i=1;i<=30000;i++)
    {
        ranking[i]=0;
        length[i]=1;
    }

    for(int i=1;i<=t;i++)
    {
        char c;
        int a,b;
        cin>>c>>a>>b;

        if(c=='M')
        {
            unite(a,b);
        }

        if(c=='C')
        {
            if(find(a)!=find(b))    printf("-1\n");

            else
            {
                printf("%d\n",abs(ranking[a]-ranking[b])-1);
            }
        }
    }

    return 0;
}
#include<iostream>

#define P 100001

using namespace std;

int fa[30000],d[30000],length[30000];

int find(int x){
    if(fa[x]==x)
    {
        d[x]=0;
        return x;
    }
    
    else
    {
        int root=find(fa[x]);
        d[x]+=d[fa[x]];
        return fa[x]=root;
    }
}

int main(){
    int p;
    scanf("%d",&p);

    for(int i=1;i<=30000;i++)    fa[i]=i,d[i]=0,length[i]=1;

    for(int i=1;i<=p;i++)
    {
        char c;
        cin>>c;

        if(c=='M')
        {
            int a,b;
            scanf("%d%d",&a,&b);

            int ra=find(a),rb=find(b);
            if(ra!=rb)
            {
                d[ra]=length[rb];
                length[rb]+=length[ra];
                fa[ra]=rb;
            }
        }

        if(c=='C')
        {
            int a;
            scanf("%d",&a);
            printf("%d\n",d[a]);
        }
    }

    return 0;
}

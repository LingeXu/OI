#include<iostream>
#include<cstring>

#define N 50001
#define K 100001

using namespace std;

int fa[N],rel[N];

int find(int x){
    if(fa[x]==x)    return x;

    int root=find(fa[x]);

    rel[x]=(rel[x]+rel[fa[x]])%3;

    return fa[x]=root;
}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);

    int cnt=0;

    for(int i=1;i<=n;i++)   fa[i]=i;
    memset(rel,0,sizeof(rel));

    for(int i=1;i<=k;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);

        if(b>n||c>n)    
        {
            cnt++;
            continue;
        }

        int rb=find(b),rc=find(c);

        if(a==1)
        {
            if(rb==rc&&rel[b]!=rel[c])
            {
                cnt++;
                continue;
            }

            if(rb==rc&&rel[b]==rel[c]);

            else
            {
                fa[rb]=rc;
                rel[rb]=(rel[c]-rel[b]+3)%3;
            }
        }

        if(a==2)
        {
            if(rb==rc&&(rel[b]-rel[c]+3)%3!=1)
            {
                cnt++;
                continue;
            }

            if(rb==rc&&(rel[b]-rel[c]+3)%3!=1);

            else
            {
                fa[rb]=rc;
                rel[rb]=(rel[c]-rel[b]+1+3)%3;
            }
        }
    }

    printf("%d\n",cnt);
    return 0;
}
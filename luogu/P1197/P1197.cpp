#include<iostream>
#include<algorithm>

#define N 100001
#define M 200001
#define K 100001

using namespace std;

struct edge{
    int u,v;
}e[M];

int d_point[K];

int fa[N];

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);

        e[i].u=a;
        e[i].v=b;
    }


    int k;
    scanf("%d",&k);

    for(int i=0;i<k;i++)
    {
        int x;
        scanf("%d",&x);

        d_point[i]=x;
    }

    int ik=0;

    while(ik<=k)
    {
        edge d_e[M];
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            bool del=false;
            for(int j=0;j<ik;j++)
            {
                if(e[i].u==d_point[j]||e[i].v==d_point[j])  del=true;
            }

            if(!del)
            {
                d_e[cnt].u=e[i].u;
                d_e[cnt].v=e[i].v;
                cnt++;
            }
        }

        for(int i=0;i<cnt;i++)  fa[i]=i;

        int ans=0,sum=0;
        while(ans<cnt){
            if(find(d_e[ans].u)!=find(d_e[ans].v))
            {
                fa[find(d_e[ans].v)]=find(d_e[ans].u);
                sum++;
            }
            ans++;
        }


        printf("%d\n",n-ik-sum);

        ik++;

        for(int i=0;i<cnt;i++)  fa[i]=i;

    }
    
    return 0;
}
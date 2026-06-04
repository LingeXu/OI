#include<iostream>
#include<algorithm>
#include<vector>

#define N 100001
#define M 200001
#define K 100001

using namespace std;

struct edge{
    int u,v;
}e[M],e_remain[10000000000];

int fa[N];

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

bool del[N];

vector<int> graph[N];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);

        e[i].u=a;
        e[i].v=b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int k;
    scanf("%d",&k);

    int del_point[N];
    for(int i=0;i<k;i++)
    {
        int x;
        scanf("%d",&x);

        del[x]=true;
        del_point[i]=x;
    }

    for(int i=0;i<n;i++)    fa[i]=i;

    int cnt1=0;
    for(int i=0;i<m;i++)
    {
        if(!del[e[i].u]&&!del[e[i].v])
        {
            e_remain[cnt1]=e[i];
            cnt1++;
        }

        /*bool deleted=false;
        for(int j=0;j<k;j++)
        {
            if(e[i].u==del_point[j]||e[i].v==del_point[j])
            {
                deleted=true;
            }
        }

        if(!deleted) 
        {
            e_remain[cnt1]=e[i]; 
            cnt1++;
        }*/
    }



    int output[K];

    int cnt=0,cnt2=0,cnt3=0;
    while(cnt<k){
        while(cnt2<cnt1){
            if(find(e_remain[cnt2].u)!=find(e_remain[cnt2].v))
            {
                fa[find(e_remain[cnt2].v)]=find(e_remain[cnt2].u);
                cnt3++;
            }
            cnt2++;
        }

        output[cnt]=n-k+cnt-cnt3;

        cnt++;

        del[del_point[k-cnt]]=false;

        /*for(int i=0;i<m;i++)
        {
            if((e[i].u==del_point[k-cnt]&&del[e[i].v]==false)||(e[i].v==del_point[k-cnt]&&del[e[i].u]==false))
            {
                e_remain[cnt1]=e[i];
                cnt1++;
            }
        }*/

        for(int v:graph[del_point[k-cnt]])
        {
            if(!del[v]) 
            {
                e_remain[cnt1]={v,del_point[k-cnt]};
                cnt1++;
            }
        }
    }



    while(cnt2<cnt1){
        if(find(e_remain[cnt2].u)!=find(e_remain[cnt2].v))
        {
            fa[find(e_remain[cnt2].v)]=find(e_remain[cnt2].u);
            cnt3++;
        }
        cnt2++;
    }

    printf("%d\n",n-cnt3);

    for(int i=cnt-1;i>=0;i--)
    {
        printf("%d\n",output[i]);
    }
    return 0;
}

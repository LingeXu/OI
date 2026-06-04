#include<iostream>
#include<cmath>

#define T 500001

using namespace std;

int fa[30000];
int length[30000];
int dist[30000];

int find(int x){
    if(fa[x]==x)   
    {
        dist[x]=0;
        return x;
    } 
    
    else
    {
        int root=find(fa[x]);
        dist[x]+=dist[fa[x]];
        return fa[x]=root;
    }  
}

int main(){
    int t;
    scanf("%d",&t);

    for(int i=0;i<30000;i++)    fa[i]=i,length[i]=1,dist[i]=0;

    for(int i=1;i<=t;i++)
    {
        char c;
        int a,b;
        cin>>c>>a>>b;

        if(c=='M')
        {
            int ra=find(a),rb=find(b);
            if(ra!=rb) 
            {
                dist[ra]=length[rb];
                length[rb]+=length[ra];
                fa[ra]=rb;
            }
        }

        if(c=='C')
        {
            if(find(a)==find(b))    printf("%d\n",abs(dist[a]-dist[b])-1);
            else printf("-1\n");
        }
    }

    return 0;
}
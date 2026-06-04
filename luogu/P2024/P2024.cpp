#include<iostream>
#include<cstring>

#define N 50001

using namespace std;

int fa[N];

int enemy1[N],enemy2[N];

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void unite(int x,int y){
    int rx=find(x),ry=find(y);
    if(rx!=ry)  fa[rx]=ry;
}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);

    for(int i=1;i<=n;i++)   fa[i]=i;

    int cnt=0;

    memset(enemy1,0,sizeof(enemy1));
    memset(enemy2,0,sizeof(enemy2));

    for(int i=1;i<=k;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);

        if(b>n||c>n)
        {
            cnt++;
            continue;
        }

        if(a==1)    
        {
            if(enemy1[find(b)]==find(c)||enemy1[find(c)]==find(b))
            {
                cnt++;
                continue;
            }

            unite(b,c);
        }

        if(a==2)    
        {
            if(find(b)==find(c)||enemy1[find(c)]==find(b))   
            {
                cnt++;
                continue;
            }

            if(enemy1[b])    unite(c,enemy1[b]);
            else    enemy1[b]=c;

            if(enemy2[c])    unite(b,enemy2[c]);
            else    enemy2[c]=b;

            if(enemy2[b])   
            {
                if(enemy1[c])   unite(enemy1[c],enemy2[b]);
                else    enemy1[c]=enemy2[b];

                if(enemy2[enemy2[b]])   unite(c,enemy2[enemy2[b]]);
                else    enemy2[enemy2[b]]=c;
            }
            
        }
    }

    printf("%d\n",cnt);
    return 0;
}
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

#define N 1001
#define M 10001

using namespace std;

int dp[M][N];

struct item{
    int a,b,c;
}x[N];

bool cmp(item x,item y)
{
    return x.c<y.c;
}

int main(){
    int m,n;
    scanf("%d%d",&m,&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&x[i].a,&x[i].b,&x[i].c);
    }

    sort(x,x+n,cmp);

   /*for(int i=0;i<n;i++)
    {
        printf("%d %d %d\n",x[i].a,x[i].b,x[i].c);
        //test1:accepted
    }*/

    
    memset(dp,0,sizeof(dp));

    for(int i=0;i<=x[n-1].c;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i>0)
            {
                dp[i][j]=dp[i-1][j];
            }

            int k1=0;
            while(x[k1].c!=i&&k1<n)
            {
                k1++;
            }

            int k2=k1;
            while(x[k2].c==i&&k2<n)
            {
                k2++;
            }

            if(k1==n)
            {
                continue;
            }

            for(int k=k1;k<k2;k++)
            {
                if(j>=x[k].a)
                {
                    dp[i][j]=max(dp[i][j],dp[i-1][j-x[k].a]+x[k].b);
                } 
            }
        }
    }

    printf("%d",dp[x[n-1].c][m]);

    return 0;
}
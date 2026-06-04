#include<iostream>
#include<vector>
#include<cmath>

#define N 32001
#define M 61
using namespace std;

struct item{
    int v,p,q;
}a[M];

vector<pair<int,int>> b;


bool cmp(item x,item y){
    return x.q<y.q;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    int v[M],p[M],q[M];
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&a[i].v,&a[i].p,&a[i].q);
    }

    sort(a,a+m,cmp);

    int dp[M][N];
    memset(dp,0,sizeof(dp));

    /*for(int i=0;i<m;i++)
    {
        for(int j=n;j>=v[i];j--)
        {
            if(a[i].q==0)
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j-a[i].v]+a[i].v*a[i].p);
            }
            else
            {
                int v[M],p[M];
                for(int k=0;k<a[i].q-1;k++)
                {
                    v[k]=a[k].v;
                    p[k]=a[k].p;
                }
                for(int k=a[i].q;k<=i;k++)
                {
                    v[k-1]=a[k].v;
                    p[k-1]=a[k].p;
                }

                
            }
        }
            
    }*/

    int ans=0;
    for(int i=0;i<m;i++)
    {
        
        if(a[i].q!=0)
        {
            ans++;

            b.push_back({a[a[i].q-1].v,a[a[i].q-1].p});
            for(int j=n;j>=a[a[i].q-1].v;j--)
            {
                dp[ans][j]=max(dp[ans-1][j],dp[ans-1][j-a[a[i].q-1].v]+a[a[i].q-1].v*a[a[i].q-1].p);
            }
            
            b.push_back({a[a[i].q-1].v+a[i].v,a[a[i].q-1].p+a[i].p});
            for(int j=n;j>=a[a[i].q-1].v+a[i].v;j--)
            {
                dp[ans][j]=max(dp[ans-1][j],dp[ans-1][j-a[a[i].q-1].v-a[i].v]+a[a[i].q-1].v*a[a[i].q-1].p+a[i].v*a[i].p);
            }

            int j=i+1;
            while(j<m&&a[j].q==a[i].q)
            {
                b.push_back({a[a[i].q-1].v+a[j].v,a[a[i].q-1].p+a[j].p});
                for(int j=n;j>=a[a[i].q-1].v;j--)
                {
                    dp[ans][j]=max(dp[ans-1][j],dp[ans-1][j-a[a[i].q-1].v-a[i].v-a[j].v]+a[a[i].q-1].v*a[a[i].q-1].p+a[i].v*a[i].p+a[j].v*a[j].p);
                }
            }
            
            i=j;
        }

 


    }


    printf("%d",dp[ans][n]);


    return 0;
}
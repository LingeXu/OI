#include<iostream>
#include<cmath>
#include<cstring>
#define N 10001
#define M 70001
#define T 1441
using namespace std;

struct tree{
    int time,value,limit;
}a[N];

struct tree2{
    int time,value;
}b[M];

int main(){
    int h1,m1,h2,m2,n;
    scanf("%d:%d %d:%d %d",&h1,&m1,&h2,&m2,&n);

    int t=(h2-h1)*60+m2-m1;

    

    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&a[i].time,&a[i].value,&a[i].limit);
    }

    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(a[i].limit!=0)
        {
            int cnt=0;
            int remain=a[i].limit;
            while(pow(2,cnt)<=remain)
            {
                b[ans].time=a[i].time*(1<<cnt);
                b[ans].value=a[i].value*(1<<cnt);

                remain-=pow(2,cnt);
                cnt++;
                ans++;
            }
    
            b[ans].time=a[i].time*remain;
            b[ans].value=a[i].value*remain;
            ans++;

        }
        
    }
    int ans2=ans;
    for(int i=0;i<n;i++)
    {
        if(a[i].limit==0)
        {
            b[ans2].time=a[i].time;
            b[ans2].value=a[i].value;
            ans2++;
        }
    }

 

    int dp[T];
    memset(dp,0,sizeof(dp));

    for(int i=0;i<ans;i++)
    {
        for(int j=t;j>=b[i].time;j--)
        {
            dp[j]=max(dp[j],dp[j-b[i].time]+b[i].value);
        }
    }

    for(int i=ans;i<ans2;i++)
    {
        for(int j=b[i].time;j<=t;j++)
        {
            dp[j]=max(dp[j],dp[j-b[i].time]+b[i].value);
        } 
    }

    printf("%d",dp[t]);

    return 0;
}

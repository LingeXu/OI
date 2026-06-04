#include<iostream>
#include<algorithm>
#define N 200001
using namespace std;

struct City{
    int x,y;
}a[N];

bool cmp(City a,City b)
{
    return a.x<b.x;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&a[i].x,&a[i].y);
    }

    sort(a,a+n,cmp);

    int dp[N];
    dp[0]=a[0].y;
    int len=1;
    for(int i=1;i<n;i++)
    {
        if(a[i].y>dp[len-1])
        {
            dp[len++]=a[i].y;
        }
        else
        {
            int left=0,right=len;
            while(left<right)
            {
                int mid=(left+right)/2;
                if(dp[mid]>a[i].y)
                {
                    right=mid;
                }
                else
                {
                    left=mid+1;
                }
            }
            dp[left]=a[i].y;
        }
    }


    printf("%d",len);
    return 0;
}
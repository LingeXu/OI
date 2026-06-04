#include<iostream>
#include<cstring>
#include<algorithm>
#define M 10001
#define T 10000001
using namespace std;

long long dp[T];  // 改用 long long

struct node{
    int time,value;
}a[M];

int main(){
    int t,m;
    scanf("%d%d",&t,&m);

    for(int i=0;i<m;i++) {
        scanf("%d%d",&a[i].time,&a[i].value);
    }

    memset(dp,0,sizeof(dp));

    for(int j=0;j<m;j++) {
        for(int i=a[j].time;i<=t;i++) {
            dp[i] = max(dp[i], dp[i - a[j].time] + a[j].value);
        }
    }

    printf("%lld", dp[t]);  // 注意输出格式
    return 0;
}
#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>

#define N 32001
#define M 61

using namespace std;

struct item{
    int v,p,q;
    vector<int> g;
}a[M];

int dp[M][N];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=1;i<=m;i++)  // 改成从1开始
    {
        scanf("%d%d%d",&a[i].v,&a[i].p,&a[i].q);  
    }

    printf("Step1: input done\n"); fflush(stdout);

    for(int i=1;i<=m;i++)
    {
        if(a[i].q != 0) {
            int master = a[i].q;
            if(master < 1 || master > m) {  // 加保护
                printf("Error: master index %d out of range\n", master);
                return 1;
            }
            a[master].g.push_back(i);
        }
    }

    printf("Step2: attach done\n"); fflush(stdout);

    memset(dp,0,sizeof(dp));

    int idx = 0;
    for(int i=1;i<=m;i++)
    {
        if(a[i].q != 0) continue;

        idx++;
        printf("Processing main %d, idx=%d\n", i, idx); fflush(stdout);

        // 继承上一组
        for(int j=0;j<=n;j++) {
            dp[idx][j] = dp[idx-1][j];
        }

        vector<pair<int,int>> plans;

        // 方案1
        plans.push_back({a[i].v, a[i].v * a[i].p});

        // 附件1
        if(a[i].g.size() >= 1) {
            int id1 = a[i].g[0];
            if(id1 < 1 || id1 > m) {
                printf("Error: attach1 index %d out of range\n", id1);
                return 1;
            }
            plans.push_back({a[i].v + a[id1].v, a[i].v*a[i].p + a[id1].v*a[id1].p});
        }

        // 附件2
        if(a[i].g.size() >= 2) {
            int id1 = a[i].g[0], id2 = a[i].g[1];
            if(id2 < 1 || id2 > m) {
                printf("Error: attach2 index %d out of range\n", id2);
                return 1;
            }
            plans.push_back({a[i].v + a[id2].v, a[i].v*a[i].p + a[id2].v*a[id2].p});
            plans.push_back({a[i].v + a[id1].v + a[id2].v,
                a[i].v*a[i].p + a[id1].v*a[id1].p + a[id2].v*a[id2].p});
        }

        printf("  plans size=%lu\n", plans.size()); fflush(stdout);

        for(int k=0; k<plans.size(); k++) {
            int w = plans[k].first;
            int val = plans[k].second;
            if(w < 0 || w > n) {
                printf("  skip plan w=%d > n=%d\n", w, n);
                continue;  // 跳过，不退出
            }
            for(int j=n; j>=w; j--) {
                dp[idx][j] = max(dp[idx][j], dp[idx-1][j-w] + val);
            }
        }
    }

    printf("Step3: DP done\n"); fflush(stdout);
    printf("%d\n", dp[idx][n]);
    return 0;
}
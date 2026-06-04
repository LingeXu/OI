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

    // 读入数据
    for(int i=1;i<=m;i++)  // 从1开始
    {
        scanf("%d%d%d",&a[i].v,&a[i].p,&a[i].q);  
    }

    // 建立附件关系
    for(int i=1;i<=m;i++)
    {
        if(a[i].q != 0) {
            int master = a[i].q;
            if(master < 1 || master > m) {
                printf("Error: master index out of range\n");
                return 1;
            }
            a[master].g.push_back(i);
        }
    }

    memset(dp,0,sizeof(dp));

    int idx = 0;  // 主件计数器
    for(int i=1;i<=m;i++)
    {
        if(a[i].q != 0) continue;  // 只处理主件

        idx++;
        printf("Processing main item %d (idx=%d)\n", i, idx); // 调试输出

        // 继承上一组
        for(int j=0;j<=n;j++) {
            dp[idx][j] = dp[idx-1][j];
        }

        // 生成方案
        vector<pair<int,int> > plans;

        // 方案1：只主件
        plans.push_back(make_pair(a[i].v, a[i].v * a[i].p));
        printf("  Plan1: w=%d v=%d\n", a[i].v, a[i].v * a[i].p);

        // 附件1
        if(a[i].g.size() >= 1) {
            int id1 = a[i].g[0];
            if(id1 < 1 || id1 > m) {
                printf("  Error: attachment1 index %d out of range\n", id1);
                return 1;
            }
            plans.push_back(make_pair(a[i].v + a[id1].v,
                a[i].v * a[i].p + a[id1].v * a[id1].p));
            printf("  Plan2: w=%d v=%d\n", a[i].v + a[id1].v,
                a[i].v * a[i].p + a[id1].v * a[id1].p);
        }

        // 附件2 和 附件1+2
        if(a[i].g.size() >= 2) {
            int id1 = a[i].g[0], id2 = a[i].g[1];
            if(id2 < 1 || id2 > m) {
                printf("  Error: attachment2 index %d out of range\n", id2);
                return 1;
            }
            plans.push_back(make_pair(a[i].v + a[id2].v,
                a[i].v * a[i].p + a[id2].v * a[id2].p));
            printf("  Plan3: w=%d v=%d\n", a[i].v + a[id2].v,
                a[i].v * a[i].p + a[id2].v * a[id2].p);

            plans.push_back(make_pair(a[i].v + a[id1].v + a[id2].v,
                a[i].v * a[i].p + a[id1].v * a[id1].p + a[id2].v * a[id2].p));
            printf("  Plan4: w=%d v=%d\n", a[i].v + a[id1].v + a[id2].v,
                a[i].v * a[i].p + a[id1].v * a[id1].p + a[id2].v * a[id2].p);
        }

        // 分组背包
        for(int k=0; k<plans.size(); k++) {
            int w = plans[k].first;
            int val = plans[k].second;
            if(w < 0 || w > n) {
                printf("  Error: weight %d out of range [0,%d]\n", w, n);
                continue;
            }
            for(int j=n; j>=w; j--) {
                dp[idx][j] = max(dp[idx][j], dp[idx-1][j-w] + val);
            }
        }
    }

    printf("Final answer: %d\n", dp[idx][n]);
    return 0;
}
//分块: 万能暴力, 区间操作 O(sqrt n); 写不动高级数据结构时的保底方案
//需预定义: int blk;  int belong[N];  块大小 = sqrt(n)
//belong[i] = (i - 1) / blk + 1;  第 i 块区间 [L, R]

void init_block() {
    blk = sqrt(n);
    for(int i = 1; i <= n; i++)    belong[i] = (i - 1) / blk + 1;
    for(int i = 1; i <= belong[n]; i++) {        //预处理每块信息(如块内和/块内排序数组)
        L[i] = (i - 1) * blk + 1;
        R[i] = min(i * blk, n);
        //如: 对块内排序维护有序数组, 支持"块内二分"
    }
}

//区间加 + 单点查询: tag[块] 懒标记
//void add(int l, int r, int val) {
//    for(int i = l; i <= min(r, R[belong[l]]); i++)    a[i] += val;        //左碎块
//    if(belong[l] != belong[r])
//        for(int i = L[belong[r]]; i <= r; i++)    a[i] += val;            //右碎块
//    for(int i = belong[l] + 1; i <= belong[r] - 1; i++)    tag[i] += val; //整块
//}
//int ask(int pos) { return a[pos] + tag[belong[pos]]; }

//区间加 + 区间求和: 整块维护 sum[块] += val * 块长, 碎块暴力改并同步 sum
//区间查询排名/第 k 小: 每块维护块内排序数组, 整块二分, 碎块暴力
//带修改的"块内排序"用 vector 维护: 整块加不改序, 碎块修改后重建该块 O(sqrt n log n)

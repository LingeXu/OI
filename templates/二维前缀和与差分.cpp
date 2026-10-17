//二维前缀和: O(1) 查询子矩阵和
//需预定义: ll pre[N][N];
void build_pre() {
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
}

//子矩阵和: (x1, y1) 左上角, (x2, y2) 右下角
ll query(int x1, int y1, int x2, int y2) {
    return pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
}

//二维差分: 子矩阵整体 +val, 全部操作完再还原
//需预定义: ll dif[N][N];
void add(int x1, int y1, int x2, int y2, int val) {
    dif[x1][y1] += val;
    dif[x2 + 1][y1] -= val;
    dif[x1][y2 + 1] -= val;
    dif[x2 + 1][y2 + 1] += val;
}

void build_dif() {                       //还原: 对 dif 本身做一次二维前缀和
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dif[i][j] += dif[i - 1][j] + dif[i][j - 1] - dif[i - 1][j - 1];
}

//一维差分: 区间 [l, r] +v 用 dif[l] += v; dif[r + 1] -= v; 前缀和还原

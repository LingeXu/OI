//并查集: 集合合并与查询, 路径压缩 + 按大小合并, 近似 O(1)
//需预定义: int fa[N], sz[N];
//入口: init(n); 之后 find / unite / same

void init(int n) {
    for(int i = 1; i <= n; i++) {
        fa[i] = i;
        sz[i] = 1;
    }
}

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);   //路径压缩
}

void unite(int x, int y) {
    int rx = find(x), ry = find(y);
    if(rx == ry)    return;
    if(sz[rx] < sz[ry])    swap(rx, ry);           //小集合并入大集合
    fa[ry] = rx;
    sz[rx] += sz[ry];
}

bool same(int x, int y) {
    return find(x) == find(y);
}

//常用技巧:
//1. 删边 -> 离线反向加边: 题目"不断删边问连通性"时, 倒着把删掉的边加回去, 答案逆序
//2. 按边权排序后逐条加边 = Kruskal 骨架(见 kruskal), 加边后集合大小可用 sz 维护

//种类并查集(扩展域): 处理"同类/异类"二元关系, 如朋友敌人、食物链
//开 2n 个节点: x 与 x+n 分别代表 x 的两种对立身份(如 x 的朋友域 / x 的敌人域)
//"x 与 y 是朋友": unite(x, y);       unite(x + n, y + n);
//"x 与 y 是敌人": unite(x, y + n);   unite(x + n, y);
//矛盾判定: 声明"x 与 y 是敌人"时若 same(x, y) 则为假话(同理声明朋友时若 same(x, y+n))

//带权并查集: 维护节点与父节点的"关系值"(模 k), 食物链 / 种类关系类问题
//语义: d[x] = (type[x] - type[fa[x]]) mod k, 即 x 相对其父亲的关系
//需预定义: int fa[N], d[N];  关系种类数 k(食物链 k = 3: 同类/吃/被吃)

int find(int x) {
    if(fa[x] == x)    return x;
    int root = find(fa[x]);
    d[x] = (d[x] + d[fa[x]]) % k;    //此时 d[fa[x]] 已压缩为 fa[x] 到 root 的关系, 先加再改父亲
    return fa[x] = root;
}

//声明"x 与 y 的关系为 rel"(type[x] - type[y] ≡ rel), 返回 false 表示与已有关系矛盾
bool unite(int x, int y, int rel) {
    int rx = find(x), ry = find(y);
    if(rx == ry)    return ((d[x] - d[y]) % k + k) % k == rel;   //同一集合直接验证
    fa[rx] = ry;
    d[rx] = ((rel - d[x] + d[y]) % k + k) % k;                  //type[rx]-type[ry] = rel-d[x]+d[y]
    return true;
}
//初始化: fa[i] = i, d[i] = 0;  查询任意两点的关系: find 后 (d[x] - d[y] + k) % k
//配套: 食物链建模: rel=0 同类, rel=1 x 吃 y; 新说法冲突即假话计数

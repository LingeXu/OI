//Tarjan 算法: 强连通分量(SCC) / 割点 / 桥, 一次 dfs 求 dfn 与 low
//需预定义: int dfn[N], low[N], dfn_cnt;   (多组数据时 dfn 需清零, 或改时间戳)
//注意: n 极大时递归可能爆栈, 可在 main 里扩栈或用迭代写法

//-------------- 有向图强连通分量 SCC(缩点) --------------
//同一 SCC 内互相可达; 缩点后为 DAG, 常配合拓扑排序做 DP
//需预定义: vector<int> graph[N];  int scc[N], scc_cnt;  int stk[N], top;  bool in_stk[N];

void tarjan_scc(int u) {
    dfn[u] = low[u] = ++dfn_cnt;
    stk[++top] = u;
    in_stk[u] = true;
    for(int v : graph[u]) {
        if(!dfn[v]) {
            tarjan_scc(v);
            low[u] = min(low[u], low[v]);
        }
        else if(in_stk[v])    low[u] = min(low[u], dfn[v]);
    }
    if(dfn[u] == low[u]) {                 //u 是分量根, 弹栈收分量
        scc_cnt++;
        int x;
        do {
            x = stk[top--];
            in_stk[x] = false;
            scc[x] = scc_cnt;
        } while(x != u);
    }
}
//调用: for(int i = 1; i <= n; i++) if(!dfn[i]) tarjan_scc(i);

//-------------- 无向图割点 --------------
//去掉 u 后连通块数增加; 根的特判: 子树个数 > 1
//需预定义: bool is_cut[N];
void tarjan_cut(int u, int fa) {
    dfn[u] = low[u] = ++dfn_cnt;
    int child = 0;
    for(int v : graph[u]) {
        if(v == fa)    continue;           //有重边时需按边编号判, 见桥的写法
        if(!dfn[v]) {
            tarjan_cut(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dfn[u] && fa != -1)    is_cut[u] = true;
            child++;
        }
        else    low[u] = min(low[u], dfn[v]);
    }
    if(fa == -1 && child > 1)    is_cut[u] = true;
}

//-------------- 无向图桥 --------------
//删掉边 (u, v) 后图不连通; low[v] > dfn[u] 时 (u, v) 是桥
//用链式前向星按边编号判重边: 见 Dinic.cpp 的前向星存法
//需预定义: bool is_bridge[M];
//调用: for(int i = 1; i <= n; i++) if(!dfn[i]) tarjan_bridge(i, -1);
void tarjan_bridge(int u, int from_edge) {
    dfn[u] = low[u] = ++dfn_cnt;
    for(int i = head[u]; i; i = e[i].next) {
        if(i == (from_edge ^ 1))    continue;    //前向星反向边, 正确处理重边
        int v = e[i].to;
        if(!dfn[v]) {
            tarjan_bridge(v, i);
            low[u] = min(low[u], low[v]);
            if(low[v] > dfn[u])    is_bridge[i] = is_bridge[i ^ 1] = true;
        }
        else    low[u] = min(low[u], dfn[v]);
    }
}

//2-SAT 完整版(SCC 判定 + 构造可行解)
//节点编号: x 真 = 2x, x 假 = 2x+1, 取反 = 节点 ^ 1(必须成对 2x/2x+1, ^1 才是取反!)
//需预定义: 前向星或 vector 存图(节点 2..2n+1, 数组大小 2n+2), 使用上面的 tarjan_scc 缩点
int node(int x, int v) {
    return 2 * x + (v ? 0 : 1);          //x 取 v 对应的节点(v 为 1 真 0 假)
}
void add_clause(int a, int va, int b, int vb) {   //"(a == va) 或 (b == vb)"
    int A = node(a, va), B = node(b, vb);
    add_edge(A ^ 1, B);                  //¬A -> B
    add_edge(B ^ 1, A);                  //¬B -> A
}
//判定: 存在 i 使 scc[2i] == scc[2i+1] 则无解;  调用: for i = 2..2n+1 if(!dfn[i]) tarjan_scc(i)
//赋值: value[i] = (scc[2i] < scc[2i+1]);  编号小的 SCC 拓扑序靠后, 取靠前(编号小)的为真
//单变量强制赋值: 强制 x 真 = add_clause(x, 1, x, 1)
//配套: 变量数 <= 1e6 时注意图大小为 2n + 2

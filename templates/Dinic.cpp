//Dinic 最大流: 一般图 O(V^2 E), 单位容量网络 O(E sqrt(V)), 实际运行远快于理论
//需预定义: struct Edge { int to, cap, next; } e[2 * M];  int head[N];  int depth[N], cur[N];
//入口: init(); add_edge(u, v, cap); dinic(s, t)

struct Edge {
    int to, cap, next;
} e[2 * M];
int head[N], edge_cnt = 1;               //从 1 开始编号, i ^ 1 即反向边
int depth[N], cur[N];

void init() {
    edge_cnt = 1;
    memset(head, 0, sizeof(head));
}

void add_edge(int u, int v, int cap) {
    e[++edge_cnt] = {v, cap, head[u]};
    head[u] = edge_cnt;
    e[++edge_cnt] = {u, 0, head[v]};     //反向边初始容量 0
    head[v] = edge_cnt;
}

bool bfs(int s, int t) {                 //分层
    memset(depth, 0, sizeof(depth));
    queue<int> q;
    q.push(s);
    depth[s] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = head[u]; i; i = e[i].next) {
            int v = e[i].to;
            if(e[i].cap && !depth[v]) {
                depth[v] = depth[u] + 1;
                q.push(v);
            }
        }
    }
    return depth[t] != 0;
}

int dfs(int u, int t, int flow) {
    if(u == t)    return flow;
    for(int& i = cur[u]; i; i = e[i].next) {         //当前弧优化
        int v = e[i].to;
        if(e[i].cap && depth[v] == depth[u] + 1) {
            int f = dfs(v, t, min(flow, e[i].cap));
            if(f) {
                e[i].cap -= f;
                e[i ^ 1].cap += f;
                return f;
            }
        }
    }
    return 0;
}

ll dinic(int s, int t) {
    ll ans = 0;
    while(bfs(s, t)) {
        memcpy(cur, head, sizeof(head));
        int f;
        while((f = dfs(s, t, INF)))
            ans += f;
    }
    return ans;
}

//配套:
//1. 最大流 = 最小割;  最小割方案: 最后一次 bfs 后 depth != 0 的点集为 S 侧
//2. 无向边: add_edge(u, v, c); add_edge(v, u, c);(正反都是 c)
//3. 二分图最大匹配: 建源点 -> 左部 -> 右部 -> 汇点, 容量全 1
//4. 带下界/费用流不在此模板内, 区域赛遇到再现场推导

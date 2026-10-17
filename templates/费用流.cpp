//最小费用最大流 MCMF: 每次沿"费用最短路"增广(SPFA 找增广路)
//复杂度上界 O(F * V * E), 实际远快; 要求无负费用环
//需预定义: struct Edge { int to, cap, cost, next; } e[2 * M];  int head[N], edge_cnt = 1;
//         int dist[N], pre[N];  bool inq[N];

void add_edge(int u, int v, int cap, int cost) {
    e[++edge_cnt] = {v, cap, cost, head[u]};
    head[u] = edge_cnt;
    e[++edge_cnt] = {u, 0, -cost, head[v]};      //反向边费用取负
    head[v] = edge_cnt;
}

bool spfa(int s, int t) {
    memset(dist, 0x3f, sizeof(dist));
    memset(inq, 0, sizeof(inq));
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    inq[s] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for(int i = head[u]; i; i = e[i].next) {
            int v = e[i].to;
            if(e[i].cap && dist[v] > dist[u] + e[i].cost) {
                dist[v] = dist[u] + e[i].cost;
                pre[v] = i;                      //记录来边, 便于沿路推流
                if(!inq[v]) {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }
    return dist[t] != INF;
}

ll min_cost, max_flow;
void mcmf(int s, int t) {
    max_flow = 0;
    min_cost = 0;
    while(spfa(s, t)) {
        int f = INF;
        for(int v = t; v != s; v = e[pre[v] ^ 1].to)    f = min(f, e[pre[v]].cap);
        for(int v = t; v != s; v = e[pre[v] ^ 1].to) {
            e[pre[v]].cap -= f;
            e[pre[v] ^ 1].cap += f;
        }
        max_flow += f;
        min_cost += 1LL * f * dist[t];
    }
}
//配套: 最大费用最大流: 边权取负求 MCMF, 答案取负; 固定流量最小费用: 达到目标流量即停
//      二分图带权匹配(指派问题) = 源->左->右->汇, 中间边费用为代价, 求 MCMF

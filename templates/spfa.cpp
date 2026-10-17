//spfa: 单源最短路 + 判负环 + 差分约束应用
vector< pair<int, int> > graph[N];
int dist[N], cnt[N];
bool inq[N];
void spfa(int s) {
    queue<int> q;
    q.push(s);
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    inq[s] = true;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        inq[x] = false;
        for(auto& e : graph[x]) {
            if(dist[e.second] > dist[x] + e.first) {
                dist[e.second] = dist[x] + e.first;
                if(!inq[e.second]) {
                    q.push(e.second);
                    inq[e.second] = true;
                    if(++cnt[e.second] > n - 1) {
                        cout << "存在负环";
                        return;
                    }
                }
            }
        }
    }
}

//差分约束: 求满足 x[i] - x[j] <= c 形式不等式组的一组最大解
//建边: 对每条约束 x[i] - x[j] <= c, 加边 j -> i 权 c
//再加超级源点 0 连所有点(权 0), 跑 spfa(0) 求最短路, dist[i] 即 x[i] 的最大可行解(可整体平移)
//无解 <=> 存在负环(此时 spfa 判出负环)
//求最小解: 约束 x[i] - x[j] >= c 加边 j -> i 权 -c(或建反向图跑最长路), 再整体取负
//常用建模: x[i] <= x[j] + c 即 x[i] - x[j] <= c;  x[i] < x[j] 可化为 x[i] - x[j] <= c - 1(整数域)
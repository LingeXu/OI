#include <bits/stdc++.h>
using namespace std;

const int MAXN = 250005;
const int INF = 0x3f3f3f3f;

int n, m, q;
int grid[MAXN];  // 一维化存储，grid[id] = INF 表示障碍
int last[MAXN];  // 记录每个点被访问时的最小阈值
bool record[MAXN];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int last_ans = 0;

struct inf {
    int id, sz;
    bool operator>(const inf& other) const {
        return sz > other.sz;
    }
};

// 将二维坐标转一维
inline int get_id(int x, int y) {
    return (x - 1) * m + y;
}

// 检查坐标是否合法
inline bool is_valid(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

int bfs(int x, int y, int sz) {
    memset(record, 0, sizeof(record));
    memset(last, -1, sizeof(last));  // 每次BFS重置
    
    int start_id = get_id(x, y);
    int res = 0;
    
    priority_queue<inf, vector<inf>, greater<inf>> pq;
    pq.push({start_id, sz});
    
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        
        int cur_id = cur.id;
        int cur_sz = cur.sz;
        
        // 剪枝：如果当前大小不大于之前到达该点的大小，跳过
        if(cur_sz <= last[cur_id]) continue;
        last[cur_id] = cur_sz;
        
        // 访问新格子
        if(!record[cur_id]) {
            res++;
            record[cur_id] = true;
        }
        
        // 计算当前坐标
        int cur_x = (cur_id - 1) / m + 1;
        int cur_y = (cur_id - 1) % m + 1;
        
        // 四个方向扩展
        for(int i = 0; i < 4; i++) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            
            if(!is_valid(nx, ny)) continue;
            
            int nid = get_id(nx, ny);
            // 如果是障碍或者鱼太大吃不了，跳过
            if(grid[nid] == INF) continue;
            if(grid[nid] > cur_sz) continue;
            
            pq.push({nid, cur_sz + 1});  // 吃掉鱼，大小+1
        }
    }
    
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m >> q;
    
    // 初始化所有格子为障碍
    for(int i = 0; i < n * m; i++) {
        grid[i] = INF;
    }
    
    for(int i = 0; i < q; i++) {
        int op, x_enc, y_enc;
        cin >> op >> x_enc >> y_enc;
        
        // 解密坐标
        int x = x_enc ^ last_ans;
        int y = y_enc ^ last_ans;
        
        if(op == 1) {
            int v;
            cin >> v;
            
            int id = get_id(x, y);
            // 计算最多能吃多少条鱼（排除自己）
            int ans = bfs(x, y, v) - 1;
            
            cout << ans << '\n';
            last_ans = ans;
            
            // 放置鱼
            grid[id] = v;
        }
        else if(op == 2) {
            int id = get_id(x, y);
            int current_size = grid[id];  // 当前鱼的大小
            
            // 先计算在足够大初始大小下能吃到的最多鱼数
            int k = bfs(x, y, INF) - 1;  // INF表示足够大
            
            // 二分查找最小的增加量
            int left = 0, right = 1e9;
            int ans = right;
            
            while(left <= right) {
                int mid = left + (right - left) / 2;
                int can_eat = bfs(x, y, current_size + mid) - 1;
                
                if(can_eat >= k) {
                    ans = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            
            cout << ans << '\n';
            last_ans = ans;
        }
    }
    
    return 0;
}
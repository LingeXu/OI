# 代码风格分析文档

## 1. 命名习惯

### 1.1 变量命名

| 变量名 | 含义 | 出现频率 |
|--------|------|----------|
| `ans` | 答案/最终结果 | 高频 |
| `n`, `m` | 数组大小/数量（如节点数、边数） | 高频 |
| `i`, `j`, `k` | 循环变量 | 高频 |
| `a`, `b`, `c` | 临时变量/输入值 | 高频 |
| `cnt` | 计数器 | 高频 |
| `sum` | 累加和 | 高频 |
| `dist` | 距离数组（图论） | 高频 |
| `fa` | 并查集父节点数组 | 高频 |
| `vis` | 访问标记数组 | 高频 |
| `inq` | 队列中标记（SPFA） | 中高频 |

**示例**：
```cpp
int ans = 0;
for(int i = 0; i < n; i++) {
    sum += a[i];
}
```

### 1.2 数组/容器命名

| 名称 | 用途 | 示例 |
|------|------|------|
| `a`, `b`, `c` | 普通数组 | `int a[N]` |
| `dp` | 动态规划状态数组 | `int dp[N][N]` |
| `graph` | 图的邻接表 | `vector<pair<int,int>> graph[N]` |
| `e` | 边数组 | `edge e[M]` |
| `dq_max`, `dq_min` | 单调队列 | `deque<int> dq_max` |

### 1.3 函数命名

| 函数名 | 用途 | 示例 |
|--------|------|------|
| `dfs` | 深度优先搜索 | `bool dfs(int x, int y)` |
| `bfs` | 广度优先搜索 | `void bfs(int start)` |
| `dijkstra` | Dijkstra 最短路径 | `void dijkstra(int start)` |
| `floyd` | Floyd 算法 | `void floyd(int u, int v, int d)` |
| `find` | 并查集查找 | `int find(int x)` |
| `unite` | 并查集合并 | `void unite(int x, int y)` |
| `mul` | 乘法（高精度） | `vector<int> mul(vector<int> a, vector<int> b)` |

---

## 2. 代码结构

### 2.1 文件组织顺序

```cpp
#include <iostream>          // 1. 头文件
#include <vector>
// ... 其他头文件

#define N 10001              // 2. 宏定义
#define INF 0x3f3f3f3f

using namespace std;         // 3. 命名空间

int a[N];                    // 4. 全局变量
int dp[N][N];

bool cmp(int x, int y) {     // 5. 函数定义
    return x > y;
}

int main() {                 // 6. 主函数
    // ...
    return 0;
}
```

### 2.2 缩进与括号风格

- **缩进**：使用空格（目测为4空格）
- **括号**：K&R 风格（左括号不换行）

**一致风格**：
```cpp
for(int i = 0; i < n; i++) {
    if(condition) {
        // code
    }
}
```

**不一致情况**：
部分代码存在单行 if 省略大括号：
```cpp
if(ok)  return 1;  // P1162.cpp:14
```

### 2.3 宏定义习惯

```cpp
#define N 10001              // 数组大小
#define M 50001              // 边数
#define INF 0x3f3f3f3f       // 无穷大（约1e9）
#define B 31                 // 二进制位数
```

---

## 3. 常用模板

### 3.1 并查集

```cpp
int fa[N];
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void unite(int x, int y) {
    int rx = find(x), ry = find(y);
    if(rx != ry) fa[rx] = ry;
}
```

### 3.2 图的邻接表存储

```cpp
vector<pair<int, int>> graph[N];

// 添加边
graph[u].push_back({w, v});
graph[v].push_back({w, u});  // 无向图
```

### 3.3 Dijkstra 算法

```cpp
int dist[N];
bool visited[N];

void dijkstra(int start) {
    memset(dist, 0x3f, sizeof(dist));
    dist[start] = 0;
    for(int i = 1; i < n; i++) {
        int u = -1, min_dist = INF;
        for(int j = 1; j <= n; j++) {
            if(!visited[j] && dist[j] <= min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }
        if(u == -1) break;
        visited[u] = true;
        for(auto &edge : graph[u]) {
            dist[edge.first] = min(dist[edge.first], dist[u] + edge.second);
        }
    }
}
```

### 3.4 单调队列（滑动窗口）

```cpp
deque<int> dq_min;
for(int i = 1; i <= n; i++) {
    while(!dq_min.empty() && dq_min.front() < i - k + 1)
        dq_min.pop_front();
    while(!dq_min.empty() && a[dq_min.back()] > a[i])
        dq_min.pop_back();
    dq_min.push_back(i);
    if(i >= k) cout << a[dq_min.front()] << ' ';
}
```

### 3.5 DFS（连通性检测）

```cpp
bool dfs(int x, int y) {
    vis[x][y] = true;
    if(IsMargin(x, y)) return 1;
    bool ok = false;
    for(int i = 0; i < 4; i++) {
        int nextx = x + dx[i];
        int nexty = y + dy[i];
        if(nextx >= 1 && nextx <= n && nexty >= 1 && nexty <= n 
           && c[nextx][nexty] == '0' && !vis[nextx][nexty])
            ok = dfs(nextx, nexty);
    }
    return ok;
}
```

---

## 4. 算法偏好

### 4.1 数据结构选择

| 场景 | 偏好数据结构 | 示例 |
|------|-------------|------|
| 图存储 | `vector<pair<int,int>>` | `graph[N]` |
| 队列操作 | `queue<int>` | BFS |
| 单调操作 | `deque<int>` | 滑动窗口 |
| 并查集 | 数组 + 路径压缩 | `fa[N]` |

### 4.2 算法使用频率

| 算法类型 | 出现频率 | 典型题目 |
|----------|----------|----------|
| 动态规划 | 高频 | P1020, P1090 |
| 贪心 | 高频 | P2240 |
| 图论（最短路） | 高频 | P3371, P4779 |
| 并查集 | 中高频 | P3367, P1525 |
| 搜索（DFS/BFS） | 中高频 | P1162 |
| 高精度计算 | 中频 | P1303 |

---

## 5. 常见失误与注意点

### 5.1 潜在问题

**问题1：数组越界风险**
```cpp
#define N 100001
int main() {
    int a[N];  // 在栈上分配大数组可能导致栈溢出
    // ...
}
```
> **注意**：大数组应使用全局变量或动态分配

**问题2：混用输入方式**
```cpp
cin >> n;           // cin
scanf("%d", &m);    // scanf
```
> **注意**：混用可能导致缓冲区问题，建议保持一致

**问题3：BFS 逻辑错误**（P4779.cpp:19-20）
```cpp
if(!visit[neighbours.first])
    visit[neighbours.first] = true;
    visited.push(neighbours.first);  // 此处缺少大括号！
```
> **注意**：缩进不代表块作用域，缺少 `{}` 导致逻辑错误

**问题4：未初始化变量**
```cpp
int ans;  // 未初始化
for(int i = 0; i < n; i++) {
    ans += a[i];  // 未定义行为
}
```

### 5.2 不一致情况

| 不一致点 | 文件示例 |
|----------|----------|
| 数组下标起始 | P1020.cpp 使用 0-index，P1162.cpp 使用 1-index |
| 输入方式 | P1001.cpp 使用 scanf，P1064.cpp 使用 cin |
| 输出方式 | 部分使用 `printf`，部分使用 `cout` |

---

## 6. 输入输出习惯

### 6.1 输入方式

**scanf 风格**（高频）：
```cpp
scanf("%d%d", &n, &m);
```

**cin 风格**（中频）：
```cpp
cin >> n >> m;
```

**混合使用**（部分代码）：
```cpp
cin >> n;
for(int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
}
```

### 6.2 输出方式

**printf**（高频）：
```cpp
printf("%d\n", ans);
printf("%.2f", ans);
```

**cout**（中频）：
```cpp
cout << ans << endl;
cout << ans << '\n';  // 推荐使用 '\n' 替代 endl
```

---

## 7. 代码优化建议

### 7.1 统一输入输出

建议统一使用 `scanf`/`printf` 或 `cin`/`cout`，避免混用。如需使用 `cin`，可添加：
```cpp
ios::sync_with_stdio(false);
cin.tie(0);
```

### 7.2 数组声明

大数组建议声明为全局变量或使用动态分配：
```cpp
// 推荐
const int N = 100001;
int a[N];  // 全局变量

// 或
vector<int> a(n);
```

### 7.3 括号规范

单行 if/else 建议添加大括号，提高可读性：
```cpp
// 推荐
if(condition) {
    return true;
}
```

---

## 附录：常见宏定义含义

| 宏 | 值 | 含义 |
|----|----|------|
| `INF` | `0x3f3f3f3f` | 约 1e9，用于表示无穷大 |
| `N` | 可变 | 数组大小（节点数） |
| `M` | 可变 | 边数 |
| `Q` | 可变 | 查询数 |
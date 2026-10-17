//多组输入: 每组数据的重置技巧 (resize / assign / 时间戳)

//vector 重置
v.clear();                 //清空所有元素, 容量不变
v.assign(n, 0);            //重置为 n 个 0
v.resize(n);               //调整长度到 n(新增部分自动为 0)
v.resize(n, val);          //新增部分填 val
v.swap(vector<int>());     //连容量一起释放(超大 vector 清空用)

//时间戳: 用全局版本号代替 memset, 每组 O(1) 而不是 O(N)
//原理: vis[x] 记录"x 最近一次被访问的版本号", == cur 才算本组访问过
int cur = 0;               //全局版本号, 每组数据(或每轮重新标记)前 ++cur
int vis[N];                //vis[x] = x 最后一次被访问时的版本号
void solve() {
    cur++;
    ...
    if(vis[x] != cur) {    //x 在本组第一次出现
        vis[x] = cur;      //打上本组标记
        //在此做该位置的初始化
    }
}

//配套: 定长 vector 每组 resize 对齐即可, 不需 clear
inf.resize(n);                  //长度与 n 对齐(旧值会被覆盖, 无需归零)
pref.assign(n + 1, 0);          //前缀和等需要归零的用 assign

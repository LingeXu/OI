//单调队列: 滑动窗口最值, O(n)
//需预定义: a[1..n];  deque 存下标
//场景: 定长窗口最值、单调队列优化 DP(多重背包、连续段 DP)、选数问题

//输出每个长度为 k 的窗口的最小值(按窗口左端点顺序), 队首即窗口最小值
void window_min(int k) {
    deque<int> dq;
    for(int i = 1; i <= n; i++) {
        while(!dq.empty() && dq.front() < i - k + 1)    dq.pop_front();  //踢掉滑出窗口的
        while(!dq.empty() && a[dq.back()] >= a[i])      dq.pop_back();   //保持队内递增
        dq.push_back(i);
        if(i >= k)    cout << a[dq.front()] << ' ';                      //窗口 [i-k+1, i] 的最小值
    }
}
//最大值: 把 >= 改成 <= (保持队内递减)

//多重背包单调队列优化: dp[j] = max(dp[j - k*w] + k*v), 对模 w 的每个同余类滑窗
//(一般竞赛先把每件物品二进制拆分(1,2,4,...个一捆)转 01 背包就够;
//  数据大到二进制也过不了时再上单调队列)

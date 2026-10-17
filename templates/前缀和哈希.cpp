//前缀和 + 哈希: 统计"子段和/异或 = k"类问题, O(n)
//核心: 子段 [l, r] 的和 = pref[r] - pref[l-1], 固定 r 时在哈希表里查满足条件的 l-1

//子段和为 k 的个数
ll count_sum_k(ll k) {
    map<ll, int> mp;                     //前缀和 -> 出现次数(用 unordered_map 更快)
    mp[0] = 1;                           //空前缀
    ll pref = 0, ans = 0;
    for(int i = 1; i <= n; i++) {
        pref += a[i];
        ans += mp[pref - k];             //之前有多少个前缀和为 pref - k
        mp[pref]++;
    }
    return ans;
}

//子段异或为 k 的个数: 把 - 换成 ^, 查 mp[pref ^ k]
//子段和为 k 的倍数: 用余数做键, 键 = (pref % k + k) % k, 查 mp[pref % k] 自身
//配套模型: 连续子段问题先想"前缀和 + 双指针/哈希/排序", 如 0-1 等量子段(1 记 +1, 0 记 -1)

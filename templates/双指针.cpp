//双指针/尺取: 维护连续段 [l, r], r 右移时 l 单调右移, 总复杂度 O(n)
//场景: 最长/最短连续子段满足某条件、两数和、去重三数和

//尺取框架: 仅当"条件随窗口单调变化"(l 只能右移不能回退)时可用
//int l = 1, ans = 0;
//for(int r = 1; r <= n; r++) {
//    add(a[r]);                       //扩展右端, 更新状态
//    while(不满足条件) {
//        del(a[l]);                   //收缩左端, 更新状态
//        l++;
//    }
//    ans = max(ans, r - l + 1);       //此时 [l, r] 满足条件
//}

//两数之和: 有序数组 a[1..n] 中是否存在 a[i] + a[j] == target
bool two_sum(int target) {
    int l = 1, r = n;
    while(l < r) {
        if(a[l] + a[r] == target)    return true;
        else if(a[l] + a[r] < target)    l++;
        else    r--;
    }
    return false;
}

//查找第一个 >= target 的位置
int Left = 0, Right = n;    // [0, n) 左闭右开
while(Left < Right) {
    int Mid = Left + (Right - Left) / 2;
    if(a[Mid] >= target)  Right = Mid;
    else    Left = Mid + 1;
}

//查找最后一个 <= target 的位置
int Left = -1, Right = n - 1;
while(Left < Right) {
    int Mid = (Left + Right + 1) >> 1;
    if(a[Mid] <= target)  Left = Mid;
    else    Right = Mid - 1;
}
//左边界
int Left = 0, Right = n - 1;
while(Left < Right) {
    int Mid = Left + (Right - Left) / 2;
    if(check(Mid))  Right = Mid;
    else    Left = Mid + 1;
}

//右边界
int Left = 0, Right = n - 1;
while(Left < Right) {
    int Mid = (Left + Right + 1) >> 1;
    if(check(Mid))  Left = Mid;
    else    Right = Mid - 1;
}
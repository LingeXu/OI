int Left = 0, Right = 1e9;
int ans = -1;
while(Left <= Right) {
    int Mid = Left + (Right - Left) / 2;
    if(check(Mid)) {
        ans = Mid;
        Right = Mid - 1;    //是Right = Mid - 1;还是Left = Mid + 1视具体情况而定
    }
    else    Left = Mid + 1;
}
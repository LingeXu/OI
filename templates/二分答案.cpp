int Left = 0, Right = 1e9;
int ans = -1;
while(Left <= Right) {
    int mid = Left + (Right - Left) / 2;
    if(check(mid)) {
        ans = mid;
        Right = mid - 1;    //是Right = Mid - 1还是Left = Mid + 1视具体情况而定
    }
    else    Left = mid + 1;
}
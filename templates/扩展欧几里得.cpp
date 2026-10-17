int exgcd(int a, int b, int& x, int& y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;    //注意用 y1: 原写法用 x 时 x 已被覆盖为 y1, 结果碰巧相同但易错
    return gcd;
}

bool solve(int a, int b, int c, int& x, int& y) {
    int gcd = exgcd(a, b, x, y);
    if(c % gcd != 0)    return false;
    x *= (c / gcd);
    y *= (c / gcd);
    //通解: x = x + k * (b/g), y = y - k * (a/g)
    //最小非负 x: x = (x % (b/g) + (b/g)) % (b/g);
    return true;
}
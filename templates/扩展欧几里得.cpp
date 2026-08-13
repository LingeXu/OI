int exgcd(int a, int b, int& x, int& y) {   //请确保a > b
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * x; 
    return gcd;
}

bool solve(int a, int b, int c, int& x, int& y) {
    int gcd = exgcd(a, b, x, y);
    if(c % gcd != 0)    return false;
    x *= (c / gcd);
    y *= (c / gcd);
    return true;
}
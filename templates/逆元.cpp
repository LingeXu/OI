bool modular_inverse(int a, int p, int& x) {    //p > 1
    int y;
    int gcd = exgcd(a, p, x, y);
    if(gcd != 1)    return false;
    x %= p;
    if(x < 0)   x += p''
    return true;
}
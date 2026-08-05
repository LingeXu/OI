ll fastpow(ll a, ll n) {
    ll result = 1;
    ll base = a;
    while(n) {
        if(n & 1)
            result *= base;
        base *= base;
        n >>= 1;
    }
    return result;
}
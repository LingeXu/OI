//快速幂: 求 a^n % MOD, O(log n)

//不带模版本(整数次幂, 注意会溢出)
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

//带模版本(竞赛常用)
ll fastpow_mod(ll a, ll n) {
    a %= MOD;                        //先取模防止溢出
    ll result = 1;
    while(n) {
        if(n & 1)
            result = result * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return result;
}

//配套: 费马小定理求逆元 fastpow_mod(a, MOD - 2), 要求 MOD 为质数且 a % MOD != 0

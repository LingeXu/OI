//Miller-Rabin 素数判定: 判 2^64 内的数, 单次 O(k log^2 n), k 个底出错概率 4^-k
//下面 7 个底对 < 2^64 的 n 是确定性的(无误差); 乘法用 __int128 防溢出

ll mul_mod(ll a, ll b, ll mod) {
    return (ll)((__int128)a * b % mod);
}

ll pow_mod(ll a, ll n, ll mod) {
    a %= mod;
    ll res = 1;
    while(n) {
        if(n & 1)    res = mul_mod(res, a, mod);
        a = mul_mod(a, a, mod);
        n >>= 1;
    }
    return res;
}

bool is_prime(ll n) {
    if(n < 2)    return false;
    for(ll p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {   //小素数先试除
        if(n % p == 0)    return n == p;
    }
    ll d = n - 1, s = 0;                     //n - 1 = d * 2^s, d 为奇数
    while(d % 2 == 0) {
        d /= 2;
        s++;
    }
    for(ll a : {2LL, 325LL, 9375LL, 28178LL, 450775LL, 9780504LL, 1795265022LL}) {
        if(a % n == 0)    continue;
        ll x = pow_mod(a, d, n);
        if(x == 1 || x == n - 1)    continue;
        bool composite = true;
        for(int i = 0; i < s - 1; i++) {
            x = mul_mod(x, x, n);
            if(x == n - 1) {
                composite = false;
                break;
            }
        }
        if(composite)    return false;
    }
    return true;
}

//配套: 分解质因数用 Pollard-Rho(Miller-Rabin + 随机); n <= 1e12 用试除到 sqrt(n) 也行

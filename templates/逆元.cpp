//乘法逆元: 三种求法, 按条件选用
//前提: 逆元存在 <=> gcd(a, mod) == 1

//法一: 费马小定理, 要求 mod 为质数
//a 的逆元 = a^(mod-2) % mod
ll inv1(ll a) {
    return fastpow_mod(a, MOD - 2);
}

//法二: 扩展欧几里得, 不要求 mod 为质数(要求 gcd(a, p) == 1)
bool modular_inverse(int a, int p, int& x) {
    int y;
    int gcd = exgcd(a, p, x, y);
    if(gcd != 1)    return false;
    x %= p;
    if(x < 0)   x += p;
    return true;
}

//法三: 线性递推 O(n) 求 1..n 所有数的逆元, 要求 mod 为质数
//需预定义: ll inv[N];
//inv[i] = (mod - mod/i) * inv[mod % i] % mod
void init_inv(int n) {
    inv[1] = 1;
    for(int i = 2; i <= n; i++)
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
}

//组合数: 预处理阶乘 + 逆元, O(1) 查询 C(n, k) % MOD (要求 MOD 为质数)
//需预定义: ll fac[N], invfac[N];
//入口: init(max_n) 一次, 之后 C(n, k) 直接查
//常见模型: 卡特兰数 C(2n,n)/(n+1), 多重集排列 n!/(c1!c2!...), 隔板法 C(n+m-1, m-1)

void init(int n) {
    fac[0] = 1;
    for(int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % MOD;
    invfac[n] = fastpow_mod(fac[n], MOD - 2);        //费马小定理求 n! 的逆元
    for(int i = n - 1; i >= 0; i--)
        invfac[i] = invfac[i + 1] * (i + 1) % MOD;   //O(n) 递推所有阶乘逆元
}

ll C(ll n, ll k) {
    if(k < 0 || k > n)    return 0;
    return fac[n] * invfac[k] % MOD * invfac[n - k] % MOD;
}

//卢卡斯定理: n, k 很大(可达 1e18)而 MOD 较小(质数, 一般 <= 1e6)时求 C(n, k) % MOD
//C(n, k) % MOD = C(n/MOD, k/MOD) * C(n%MOD, k%MOD) % MOD
//注意: 需先把 fac / invfac 预处理到 MOD - 1
ll Lucas(ll n, ll k) {
    if(k == 0)    return 1;
    return C(n % MOD, k % MOD) * Lucas(n / MOD, k / MOD) % MOD;
}

//配套: MOD 较小且只查少量组合数时, 可用杨辉三角 O(n^2) 预处理所有 C[i][j], 不需要逆元

//中国剩余定理 CRT: 解 x ≡ r[i] (mod m[i]), 所有 m[i] 两两互质
//需预定义: 快速幂 fastpow_mod 与 exgcd(见 扩展欧几里得.cpp)
ll crt(ll r[], ll m[], int k) {
    ll M = 1;
    for(int i = 0; i < k; i++)    M *= m[i];
    ll ans = 0;
    for(int i = 0; i < k; i++) {
        ll Mi = M / m[i];
        ll x, y;
        exgcd(Mi % m[i], m[i], x, y);        //Mi 在 mod m[i] 下的逆元(exgcd 版, 不要求 m[i] 为质数)
        x = (x % m[i] + m[i]) % m[i];
        ans = (ans + r[i] % M * Mi % M * x) % M;
    }
    return (ans % M + M) % M;                //最小非负解, 通解 x + t*M
}

//扩展 CRT(exCRT): 模数不保证互质, 两两合并
//合并 x ≡ r1 (mod m1) 与 x ≡ r2 (mod m2): 解 r1 + m1*t ≡ r2 (mod m2)
ll excrt(ll r[], ll m[], int k) {
    ll m1 = m[0], r1 = r[0];
    for(int i = 1; i < k; i++) {
        ll m2 = m[i], r2 = r[i], x, y;
        ll g = exgcd(m1, m2, x, y);
        if((r2 - r1) % g != 0)    return -1;      //无解
        x = x * ((r2 - r1) / g) % (m2 / g);
        x = (x % (m2 / g) + (m2 / g)) % (m2 / g);
        r1 = r1 + m1 * x;
        m1 = m1 / g * m2;
        r1 = (r1 % m1 + m1) % m1;
    }
    return (r1 % m1 + m1) % m1;
}

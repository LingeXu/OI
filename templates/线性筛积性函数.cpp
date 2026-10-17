//线性筛(欧拉筛)同时求积性函数: phi欧拉函数 / mu莫比乌斯函数 / d约数个数 / sigma约数和
//原理: 每个合数只被最小质因子筛一次; 积性函数按 i % p == 0(p是否为i的最小质因子)分情况递推
//复杂度 O(n); 入口: sieve(n)

vector<int> primes;
bool is_comp[N];
int phi[N], mu[N];
int cnt_min[N];                //i 的最小质因子的指数, 仅用于递推 d 和 sigma
ll d[N], sigma[N];

void sieve(int n) {
    phi[1] = 1;
    mu[1] = 1;
    d[1] = 1;
    sigma[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(!is_comp[i]) {
            primes.push_back(i);
            phi[i] = i - 1;
            mu[i] = -1;
            cnt_min[i] = 1;
            d[i] = 2;
            sigma[i] = i + 1;
        }
        for(int p : primes) {
            if(1LL * i * p > n)    break;
            is_comp[i * p] = true;
            if(i % p == 0) {
                //p 是 i 的最小质因子(故也是 i*p 的最小质因子)
                phi[i * p] = phi[i] * p;
                mu[i * p] = 0;                                     //含平方因子
                cnt_min[i * p] = cnt_min[i] + 1;
                d[i * p] = d[i] / (cnt_min[i] + 1) * (cnt_min[i] + 2);
                sigma[i * p] = sigma[i] + p * (sigma[i] - sigma[i / p]);
                break;                                             //保证每个合数只筛一次
            }
            //p < i 的最小质因子, 与 i 互质, 积性函数直接相乘
            phi[i * p] = phi[i] * (p - 1);
            mu[i * p] = -mu[i];
            cnt_min[i * p] = 1;
            d[i * p] = d[i] * 2;
            sigma[i * p] = sigma[i] * (p + 1);
        }
    }
}

//配套结论:
//1. sum_{d|n} phi(d) = n (欧拉反演);   sum_{d|n} mu(d) = [n==1]
//2. 求单个 phi 可 O(sqrt(n)): phi(n) = n * prod(1 - 1/p), 枚举质因子

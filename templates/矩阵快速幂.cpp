//矩阵快速幂: 线性递推加速(如斐波那契第 n 项)、图上走 k 步的路径数
//需预定义: 矩阵大小 SZ; 调用: Matrix ans = mat_pow(base, n)
//i-k-j 循环顺序(先枚举 k)利于内存连续, 且 x.a[i][k]==0 时跳过可加速稀疏矩阵

#define SZ 2                            //矩阵大小, 按需修改

struct Matrix {
    ll a[SZ][SZ];
    Matrix() {
        memset(a, 0, sizeof(a));
    }
};

Matrix mat_mul(Matrix x, Matrix y) {
    Matrix res;
    for(int i = 0; i < SZ; i++)
        for(int k = 0; k < SZ; k++) {
            if(x.a[i][k] == 0)    continue;
            for(int j = 0; j < SZ; j++)
                res.a[i][j] = (res.a[i][j] + x.a[i][k] * y.a[k][j]) % MOD;
        }
    return res;
}

Matrix mat_pow(Matrix base, ll n) {
    Matrix res;
    for(int i = 0; i < SZ; i++)
        res.a[i][i] = 1;               //单位矩阵
    while(n) {
        if(n & 1)    res = mat_mul(res, base);
        base = mat_mul(base, base);
        n >>= 1;
    }
    return res;
}

//示例: 斐波那契 f[n] = f[n-1] + f[n-2], f[0]=0, f[1]=1
//Matrix base;
//base.a[0][0] = base.a[0][1] = base.a[1][0] = 1;
//Matrix ans = mat_pow(base, n);                 // [f(n+1), f(n)]^T = ans * [f(1), f(0)]^T
//f[n] = ans.a[1][0];                            //即第二行第一列

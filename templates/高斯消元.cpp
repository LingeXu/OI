//高斯消元: 解线性方程组 / 异或方程组 / 求行列式与逆矩阵
//需预定义: double a[N][N];  a[i][1..n] 为第 i 个方程的系数, a[i][n+1] 为常数
//返回: 0 = 唯一解(x[i] = a[i][n+1]) / 1 = 无穷解 / -1 = 无解

int gauss(int n) {
    int row = 1;
    for(int col = 1; col <= n; col++) {
        int pivot = row;
        for(int i = row + 1; i <= n; i++)                     //选主元: 该列绝对值最大
            if(fabs(a[i][col]) > fabs(a[pivot][col]))    pivot = i;
        if(fabs(a[pivot][col]) < eps)    continue;            //该列全 0, 自由变量
        for(int j = col; j <= n + 1; j++)    swap(a[row][j], a[pivot][j]);
        for(int j = n + 1; j >= col; j--)    a[row][j] /= a[row][col];
        for(int i = 1; i <= n; i++)                            //消去其他行的该列
            if(i != row && fabs(a[i][col]) > eps)
                for(int j = n + 1; j >= col; j--)
                    a[i][j] -= a[i][col] * a[row][j];
        row++;
    }
    if(row <= n) {                                            //有自由变量
        for(int i = row; i <= n; i++)
            if(fabs(a[i][n + 1]) > eps)    return -1;         //0 = 非零 -> 无解
        return 1;
    }
    return 0;
}

//异或方程组: 把 +-*/ 换成 ^, 常数/系数只有 0/1, 用 bitset 存储加速
//需预定义: #define MAXN 2005;  bitset<MAXN> xa[MAXN];  xa[i] 的第 j 位为系数, 第 n+1 位为常数
int gauss_xor(int n) {
    int row = 1;
    for(int col = 1; col <= n; col++) {
        int pivot = row;
        for(int i = row; i <= n; i++)
            if(xa[i][col]) { pivot = i; break; }
        if(!xa[pivot][col])    continue;
        swap(xa[row], xa[pivot]);
        for(int i = 1; i <= n; i++)
            if(i != row && xa[i][col])    xa[i] ^= xa[row];
        row++;
    }
    if(row <= n) {
        for(int i = row; i <= n; i++)
            if(xa[i][n + 1])    return -1;                     //无解
        return 1;                                             //无穷解(自由变量取 0 即一个解)
    }
    return 0;                                                 //唯一解: x[i] = xa[i][n+1]
}

//配套: 求行列式: 高斯消元成上三角, det = 主对角线乘积 * (每交换一次行取一次负号)
//     求逆矩阵: 把 [A | I] 消成 [I | A^-1]

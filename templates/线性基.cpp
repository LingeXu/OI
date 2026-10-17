//线性基: 处理异或问题的工具, 维护一组基使任意子集异或都能被基的异或表示
//需预定义: ll basis[64];   basis[i] = 最高位为 i 的基向量, 0 表示不存在
//注意: 1e18 用 61 位基; 移位用 >> 而不是 (1LL << i), 防止 2^63 溢出

bool insert(ll x) {                     //插入元素, 返回 false 表示 x 已被已有基表示
    for(int i = 61; i >= 0; i--)
        if(x >> i & 1) {
            if(!basis[i]) {
                basis[i] = x;
                return true;
            }
            x ^= basis[i];              //消去最高位, 继续
        }
    return false;
}

ll get_max() {                          //子集异或最大值
    ll res = 0;
    for(int i = 61; i >= 0; i--)
        if((res ^ basis[i]) > res)    res ^= basis[i];
    return res;
}

//第 k 小异或: 先把基消成"每列至多一个 1"的阶梯形, 非零基按位升序排列后 k 的二进制分解
void rebuild() {                        //阶梯化
    for(int i = 61; i >= 0; i--)
        for(int j = i - 1; j >= 0; j--)
            if(basis[i] >> j & 1)    basis[i] ^= basis[j];
    //把非零基提到数组 tmp[0..cnt-1] 按位升序, 则第 k 小 = 各 tmp 按 k 的二进制位异或
}
//配套: 判断 x 能否被表示 = !insert(x)(或 insert 后再 erase 掉); 线性相关判定同理
//     多个线性基求并/交等进阶操作区域赛少见, 遇到现推

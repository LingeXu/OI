int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);  //需要确保第一个参数大于等于第二个参数
}
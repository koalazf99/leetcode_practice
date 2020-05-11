class Solution {
//快速幂算法
//例如求3^11 = 3^(1011) = 3^(1000) * 3^(10) * 3(1)
//每次增大底数为底数的平方，并将指数不断循环右移一位
public:
    double myPow(double x, int n) {
        double res = 1.0;
        if (n == 0 || x == 1.0)
            return (double) 1;
        long long N;
        //int的范围在[-2^31, 2^31-1]
        //所以不能直接用abs，否则abs(-2^31)会溢出
        if (n < 0)
            N = -1.0 * n;
        else
            N = n;
        for (long long i = N; i!=0; i = i >> 1)
        {
            if (i % 2 == 1)
                res *= x;
            x *= x;
        }
        if (n < 0)
            return 1.0 / res;
        else
            return res;
    }
};
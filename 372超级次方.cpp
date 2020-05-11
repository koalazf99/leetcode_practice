class Solution {
public:
    int cuspow(int a, int pow){
        long long ret = 1;
        for (int i=0; i<pow; ++i){
            ret *= a;
            ret = ret % 1337;
        }
        return ret;
    }
    int superPow(int a, vector<int>& b) {
        a = a % 1337;
        long long  res = 1;
        for (int i = 0; i < b.size(); ++i){
            res = res % 1337;
            res = (long long) cuspow(res, 10) % 1337;
            res *= (long long) cuspow(a, b[i]) % 1337;
        }
        return (int)res % 1337;
    }
};
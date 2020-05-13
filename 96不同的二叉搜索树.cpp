class Solution {
public:
    int numTrees(int n) {
        int *dp = new int [n + 1];
        dp[0] = 1;
        dp[1] = 1;
        if (n < 2)
            return dp[n];
        for (int i = 2; i <= n; ++i){
            int num = 0;
            for (int j = 0; j <= i-1; ++j)
                num += dp[j] * dp[i - 1 - j];
            dp[i] = num;
        }
        return dp[n];
    }
};
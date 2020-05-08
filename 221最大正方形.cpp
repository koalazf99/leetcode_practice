/*
动态规划，对于点[i,j], 若他是某个正方形的右下角，则[i-1, j], [i-1, j-1], [i. j-1]也必须是正方形的右下角
然后取三者中正方形边长的最小值，dp[i,j] = 1 + min(dp[i-1, j], dp[i-1, j-1], dp[i, j-1]);
注意base case

*/

class Solution {
public:
    int Min(int x, int y, int z){
        int res = (x>y?y:x);
        return (res>z?z:res);
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int i, j;
        int res = 0;
        int m = matrix.size();
        if (!m) return res;
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));

        for (int i = 0; i < m; ++i){
            dp[i][0] = (matrix[i][0] == '1'?1:0);
            dp[i][n-1] = (matrix[i][n-1] == '1'?1:0);
            if (dp[i][0] || dp[i][n-1]) 
                res = 1;
        }
        for (int j = 0; j < n; ++j){
            dp[0][j] = (matrix[0][j] == '1'?1:0);
            dp[m-1][j] = (matrix[m-1][j] == '1'?1:0);
            if (dp[0][j] || dp[m-1][j]) 
                res = 1;
        }

        for (int i = 1; i < m; ++i){
            for (int j = 1; j < n; ++j){
                if (matrix[i][j] == '1'){
                    dp[i][j] = 1 + Min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]);
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res * res;
    }
};
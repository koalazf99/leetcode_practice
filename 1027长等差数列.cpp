class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        unordered_map<int, unordered_map<int, int> > dp;
        int maxlen = 0;
        for (int i = 1; i < A.size(); i++){
            for (int j = 0; j < i; j++){
                int diff = A[i] - A[j];
                if (dp[j][diff] > 0){
                    dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
                }
                if (!dp[i][diff]) dp[i][diff] = 2;

                maxlen = max(maxlen, dp[i][diff]);
            }
        }   
        return maxlen;
    }
};
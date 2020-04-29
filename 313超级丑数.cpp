class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int *idx = new int[primes.size()];
        int *dp = new int[n+1];
        dp[0] = 1;
        for (int i=0; i<primes.size(); ++i){
            idx[i] = 0;
        }
        for (int i=1; i<n; ++i){
            dp[i] = INT_MAX;
            for (int j=0; j<primes.size(); ++j){
                dp[i] = min(dp[i], dp[idx[j]]*primes[j]);
            }
            for (int j=0; j<primes.size(); ++j){
                if (dp[i] == dp[idx[j]]*primes[j]) idx[j]+=1;
            }
        }
        return dp[n-1];

    }
};
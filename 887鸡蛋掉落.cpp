class Solution {
public:
    int superEggDrop(int K, int N){
        int i,j;
        int memo[K+1][N+1];
        // base situation
        for (int j=0; j<=N; ++j) memo[1][j] = j;
        for (int i=0; i<=K; ++i) memo[i][0] = 0;
        for (int i=2; i<=K; ++i){
            for (int j=1; j<=N; ++j){
                int tmp=20000, left, right;
                int l=1, r=j, mid=(l+r)/2;
                while (l<=r){
                    left = memo[i-1][mid-1]; 
                    right = memo[i][j-mid];
                    if (left>right) 
                        {r=mid-1; mid=(l+r)/2; tmp=min(tmp, left+1);}
                    else if (left<=right) 
                        {l=mid+1; mid=(l+r)/2; tmp=min(tmp, right+1);}
                }
                memo[i][j] = tmp;
            }
        }
        return memo[K][N];
    }
};
class Solution {
public:
    int M;
    int N;
    bool judge(int x, int y){
        return (0 <= x && x < M && 0 <= y && y < N);
    }
    void dfs(int x, int y, vector<vector<int>>& A){
        if (!judge(x, y) || A[x][y] == 0)
            return;
        A[x][y] = 0;
        dfs(x - 1, y, A);
        dfs(x + 1, y, A);
        dfs(x, y - 1, A);
        dfs(x, y + 1, A);
        return;
    }
    int numEnclaves(vector<vector<int>>& A) {
        int cnt = 0;
        M = A.size();
        N = A[0].size();
        for (int i = 0; i < A.size(); ++i){
            dfs(i, 0, A);
            dfs(i, N - 1, A);
        }
        for (int j = 0; j < A[0].size(); ++j){
            dfs(0, j, A);
            dfs(M - 1, j, A);
        }
        for (int i = 0; i < A.size(); ++i){
            for (int j = 0; j < A[0].size(); ++j){
                if (A[i][j] == 1)
                    cnt ++;
            }
        }
        return cnt;
    }
};
class Solution {
public:
    vector <vector<int>> height;
    int M;
    int N;
    int maximalRectangle(vector<vector<char>>& matrix) {
        M = matrix.size();
        if (!M) return 0;
        N = matrix[0].size();
        height = vector(M, vector<int>(N, 0));
        int res = 0;
        for (int j = 0; j < N; ++j){
            height[0][j] =  (matrix[0][j]=='1'?1:0);
        }
        res = find_largest_rectangle(0);
        for (int i = 1; i < M; ++i){
            for (int j = 0; j < N; ++j){
                if (matrix[i][j] == '1'){
                    height[i][j] = height[i-1][j] + 1;
                }
                else
                    height[i][j] = 0;
            }
            res = max(res, find_largest_rectangle(i));
        }
        return res;
    }

    int find_largest_rectangle(int m){
        int *left = new int[N];
        int *right = new int[N];
        left[0] = -1;
        right[N-1] = N;
        int res = 0;
        for (int i = 1; i < N; ++i){
            int min = i - 1;
            while (min >= 0 && height[m][min] >= height[m][i])
                min = left[min];
            left[i] = min;
        }
        for (int i = N - 2; i >= 0; --i){
            int min = i + 1;
            while (min < N && height[m][min] >= height[m][i])
                min = right[min];
            right[i] = min;
        }
        for (int i = 0; i < N; ++i)
            res = max(res, height[m][i] * (right[i] - left[i] - 1));
        return res;
    }
};
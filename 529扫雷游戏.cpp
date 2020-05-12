class Solution {
public:
    vector<int> cd_x = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> cd_y = {-1, 0, 1, -1, 1, -1, 0, 1};
    vector< vector<char> >Board;
    vector< vector<bool> >memo;
    int M;
    int N;
    bool judge(int x, int y){
        return (0 <= x && x < M && 0 <= y && y < N);
    }

    void dfs(int x, int y){
        //判断周围的点地雷的数量
        if (Board[x][y] != 'E' || x < 0 || x >= M 
                                || y < 0 || y >=N)
            return;
        int cnt = 0;
        for (int i = 0; i < 8; ++i){
            int x_n = x + cd_x[i], y_n = y + cd_y[i];
            if (judge(x_n, y_n)){
                if (Board[x_n][y_n] == 'M'){
                    cnt += 1;
                }
            }
        }
        if (cnt > 0){
            Board[x][y] = '0' + cnt;
        }
        else{
            Board[x][y] = 'B';
            for (int i = 0; i < 8; ++i){
                int x_n = x + cd_x[i], y_n = y + cd_y[i];
                if (judge(x_n, y_n) && !memo[x_n][y_n]){
                    memo[x_n][y_n] = true;
                    dfs(x_n, y_n);
                }
            }
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        Board = board;
        M = board.size();
        N = board[0].size();
        memo = vector(M, vector<bool>(N));
        for (int i = 0; i < M; ++i){
            for (int j = 0; j < N; ++j)
                memo[i][j] = false;
        }
        memo[click[0]][click[1]] = true;
        if (board[click[0]][click[1]] == 'M'){
            Board[click[0]][click[1]] = 'X';
            return Board;
        }
        dfs(click[0], click[1]);
        return Board;
    }
};
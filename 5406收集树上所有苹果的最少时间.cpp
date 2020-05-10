class Solution {
public:
    vector< vector<int> > tree;
    vector<bool> has;
    vector<bool> memo;
    // 返回当前idx下的所有苹果的时间
    int dfs(int cur, int expected){
        memo[cur] = has[cur];
        for (int i = 0; i < tree[cur].size(); ++i){
            expected += dfs(tree[cur][i], 0);
            if (memo[tree[cur][i]]) 
                memo[cur] = true;
        }
        if (memo[cur]){
            expected += 2;
        }
        return expected;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        memo = vector<bool>(n, false);
        tree = vector< vector<int> >(n);
        for (int i = 0; i < n; ++i)
            has.push_back(hasApple[i]);
        for (int i = 0; i < edges.size(); ++i){
            tree[edges[i][0]].push_back(edges[i][1]);
        }
        return max(dfs(0, 0) - 2, 0);
    }
};
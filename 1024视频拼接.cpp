class Solution {
public:
    //动态规划
    //dp[j] 表示[0-j]时刻所用的最少的片段
    int videoStitching(vector<vector<int>>& clips, int T) {
        if (clips.size() == 0)
            return (T == 0);
        vector<int> dp(T+1, T+1);
        dp[0] = 0;
        for (int t = 1; t<=T; t++){
            for (int i = 0; i < clips.size(); ++i){
                if (clips[i][0] <= t && clips[i][1] >= t)
                    dp[t] = min(dp[t], dp[clips[i][0]] + 1);
            }
        }
        if (dp[T] == T + 1)
            return -1;
        else 
            return dp[T];
    }
};


class Solution {
public:
    //贪心算法
    int videoStitching(vector<vector<int>>& clips, int T) {
        if (clips.size() == 0)
            return (T == 0);
        sort(clips.begin(), clips.end(), [](vector<int> a, vector<int> b){
            return (a[0] < b[0] || ((a[0] == b[0]) && (a[1] > b[1])));
        });

        // 表示当前片段的开始，结束位置
        int start = clips[0][0];
        if (start > 0)
            return -1;
        int end = clips[0][1];
        // 表示共有多少片段
        int cnt = 1;
        int i = 1;
        while (i < clips.size() && end < T){
            if (clips[i][0] > end)
                return -1;
            //每次向后挑选：在上个结束区间内开始，且结束时间最晚的片段作为下一个被选中的
            int max_ = end;
            while (i < clips.size() && clips[i][0] <= end){
                max_ = max(clips[i][1], max_);
                i++;
            }
            end = max_;
            cnt++;
        }

        if (end < T) 
            return -1;
        else 
            return cnt;
    }
};
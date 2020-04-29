class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // vector<string> dp(s.size());
        if (s.size()==0) return 0;
        int res=1;
        // for (int i=0; i<s.size(); ++i){
        //     dp[i] = s[i];
        // }
        // for (int i=1; i<s.size(); ++i){
        //     if (dp[i-1].rfind(dp[i])==string::npos) {
        //         dp[i] = dp[i-1]+dp[i];
        //     }
        //     else{
        //         int pos = s.substr(0,i).rfind(dp[i]);
        //         dp[i] = s.substr(pos+1, i-pos);
        //     }
        //     res = (res>dp[i].size())?res:dp[i].size();
        // }
        // return res;
        string pre,cur;
        pre = s.substr(0, 1);
        for (int i=0; i<s.size(); ++i){
            cur = s[i];
            if (pre.rfind(cur)==string::npos){
                cur = pre + cur;
                pre = cur;
            }
            else{
                int pos = s.substr(0, i).rfind(cur);
                cur = s.substr(pos+1, i-pos);
                pre = cur;
            }
            res = (res>cur.size())?res:cur.size();
        }
        return res;
    }
};
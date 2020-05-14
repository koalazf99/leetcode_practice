class Solution {
public:
    vector< vector<int> > res;
    // cur 当前的组合， sum 当前组合的和， index 当前组合最后一位的下标(为了不重复)
    void BT(vector<int>& candidates, vector<int> cur, int sum, int target, int index){
        if (sum == target){
            res.push_back(cur);
            return;
        }
        for (int i = index; i < candidates.size(); ++i){
            if (candidates[i] + sum <= target){
                cur.push_back(candidates[i]);
                BT(candidates, cur, sum + candidates[i], target, i);
                cur.pop_back();
            }
            else{
                break;
            }
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        BT(candidates, tmp, 0, target, 0);
        return res;
    }
};
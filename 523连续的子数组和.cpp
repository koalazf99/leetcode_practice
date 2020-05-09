class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        //特殊情况处理
        if (nums.size() <= 1) return false;
        if (k == 0) {
            int cnt = 0;
            for (int i = 0; i < nums.size(); ++i){
                if (nums[i] == 0){
                    cnt ++;
                    if (cnt > 1) return true;
                }
                else{
                    cnt = 0;
                }
            }
            return false;
        }

        k = abs(k);
        // 求前缀和 total[i] = nums[1] + ... nums[i]
        int* total = new int[nums.size()+1];
        total[0] = 0;
        for (int i = 1; i <= nums.size(); ++i){
            total[i] = (total[i-1] + nums[i-1]) % k;
        }

        //dp
        for (int i = 0; i <= nums.size(); ++i){
            for (int j = i + 2; j <= nums.size(); ++j){
                if ((total[j] - total[i]) % k == 0)
                    return true;
            }
        }
        return false;
    }
};
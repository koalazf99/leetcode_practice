/***************************************************
双指针,和三数之和类似
***************************************************/
class Solution {
public:

    bool cmp(int cur, int res, int target){
        if (abs(cur-target) < abs(res-target)) return true;
        return false;
    }

    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        for (int i=0; i<nums.size()-2; ++i){
            if (res == target) break;
            int left = i + 1, right = nums.size()-1;
            while (left<right){
                if ((nums[i] + nums[left] + nums[right])<target){
                    while (left<right && (nums[i] + nums[left] + nums[right]<target)) left++;
                    if (cmp(nums[i]+nums[left-1]+nums[right], res, target)) 
                        res = nums[i] + nums[left-1] + nums[right];
                    if (cmp(nums[i]+nums[left]+nums[right], res, target) && left<right)
                        res = nums[i] + nums[left] + nums[right];
                    right--;
                }
                else if (nums[i]+nums[left]+nums[right]>target){
                    while (left<right && (nums[i] + nums[left] + nums[right]>target)) right--;
                    if (cmp(nums[i]+nums[left]+nums[right+1], res, target))
                        res = nums[i] + nums[left] + nums[right+1];
                    if (cmp(nums[i]+nums[left]+nums[right], res, target) && left <right)
                        res = nums[i] + nums[left] + nums[right];
                    left ++;
                }
                else if (left<right){
                    res = target;
                    break;
                }
            }
        }
        return res;
    }
};
/****************************************************************
三数之和：
nums中是否存在三个元素a,b,c, a+b+c=0?
find all of them

枚举i为开始位置
L,R为(i, end-1)下的两个指针，判断三者之和
并注意重复的元素需要去除。


****************************************************************/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i=0;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (nums.size()<3) return res;
        while (i<nums.size()-2)
        {
            if (nums[i]>0) break;
            int L=i+1, R=nums.size()-1;
            while(L<R){
                if (nums[i]+nums[L]+nums[R]>0){
                    R--;
                }
                else{
                    if (nums[i]+nums[L]+nums[R]<0){
                        L++;
                    }
                    else{
                        res.push_back({nums[i], nums[L], nums[R]});
                        while (L<R && nums[L]==nums[L+1]) L++;
                        while (L<R && nums[R]==nums[R-1]) R--;
                        // nums[L] != nums[L+1], nums[R] != nums[R+1]
                        L++;
                        R--;
                    }
                }
            }
            while (i+1<nums.size() && nums[i]==nums[i+1]) i++;
            i++;
        }
        return res;
    }
};
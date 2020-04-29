class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        //vector自带排序，从小到大
        sort(nums.begin(), nums.end());
        int i=0, j=1, tot=0;
        while (j<nums.size()){
            while (j<nums.size() && nums[j]-nums[i]<k) j++;
            while (j<nums.size() && i<j && nums[j]-nums[i]>k) i++;
            if (i<j && j<nums.size() && nums[j]-nums[i]==k) {
                tot++;
                while ((++j)<nums.size() && nums[j]==nums[j-1]) {}
                while ((++i)<nums.size() && nums[i]==nums[i-1]) {}
            }
            else{
                j++;
            }
        }
        return tot;
    }
};
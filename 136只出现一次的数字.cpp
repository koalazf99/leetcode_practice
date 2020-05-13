// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int i = 0;
//         while (i < nums.size() - 1){
//             if (nums[i] == nums[i + 1]) i += 2;
//             else return nums[i];
//         }
//         return nums[nums.size() - 1];
//     }
// };
// 异或交换律 a^b^c = a^c^b ....
// a ^ 0 = a
// a ^ a = 0
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i){
            res = res ^ nums[i];
        }
        return res;
    }
};
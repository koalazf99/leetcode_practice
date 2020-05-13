// 能否覆盖[0, nums.size() - 1]
// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         vector< vector<int> > a;
//         for (int i = 0; i < nums.size(); ++i){
//             a.push_back({i, i + nums[i]});
//         }
//         sort(a.begin(), a.end(), [](vector<int> a, vector<int> b){
//             return (a[0] < b[0] || ((a[0] == b[0]) && (a[1] > b[1])));
//         });
//         int start = a[0][0];
//         int end = a[0][1];
//         int i = 1;
//         while (i < nums.size() - 1){
//             int max_ = end;
//             while (i < nums.size() - 1 && i <= end){
//                 max_ = max(a[i][1], max_);
//                 i++;
//             }
//             if (end >= nums.size() - 1)
//                 return true;
//             if (max_ == end)
//                 return false;
//             end = max_;
//         }
//         return (end >= nums.size() - 1);
//     }
// };
// class Solution{
//     public:
//     bool canJump(vector<int> &nums){
//         int far = nums[0] + 0;
//         for (int i = 1; i <nums.size(); ++i){
//             if (i <= far){
//                 far = max(far, i +nums[i]);
//             }
//             else
//                 return false;
//         }
//         return (far >= nums.size() - 1);
//     }
// };
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() - 1, m = nums[0];
        for (int i = 0; i < m + 1; i++)
        {
            m = max(nums[i] + i, m);
            if (m+1 > n) return true;
        }
        return false;
    }
};
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         if (heights.size() == 0)
//             return 0;
//         vector< vector<int>> dp = vector(heights.size(), vector<int>(heights.size(), INT_MAX));
//         for (int i = 0; i < heights.size(); ++i)
//             dp[i][i] = heights[i];
//         long long res = dp[0][0];
//         for (int i = 0; i < heights.size(); ++i){
//             res = (dp[i][i] > res?dp[i][i]:res);
//             for (int j = i + 1; j <heights.size(); ++j){
//                 dp[i][j] = -1 * max(-1 * dp[i][j-1], -1 * heights[j]);
//                 res = ((long long)(dp[i][j] * (j - i + 1))>res?(long long)(dp[i][j] * (j - i + 1)):res);
//             }
//         }
//         return res;
//     }
// };
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0)
            return 0;
        int res = 0;
        int *left = new int[heights.size()];
        int * right = new int[heights.size()];
        left[0] = -1;
        right[heights.size() - 1] = heights.size();
        for (int i = 1; i < heights.size(); i++){
            int min = i - 1;
            while (min >= 0 && heights[min] >= heights[i])
                min = left[min];
            left[i] = min;
        }
        for (int i = heights.size() - 2; i >= 0; i--){
            int min = i + 1;
            while (min <= heights.size() - 1 && heights[min] >= heights[i])
                min = right[min];
            right[i] = min;
        }

        for (int i = 0; i < heights.size(); i++){
            res = max((right[i] - left[i] - 1) * heights[i], res);
        }
        return res;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size()==0) return 0;
        int left = 0, right = height.size()-1;
        int max_left = height[left], max_right = height[right];
        int res = 0;
        while (left < right){
            if (max_left < max_right){
                res += max(max_left - height[left], 0);
                left++;
                max_left = max(max_left, height[left]); 
            }
            else{
                res += max(max_right - height[right], 0);
                right--;
                max_right = max(max_right, height[right]);
            }
        }
        return res;
    }
};
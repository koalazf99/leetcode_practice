class Solution {
public:
    struct cmp{
            bool operator ()(pair<int, int> &a, pair<int, int> &b) {
                return a.first+a.second<b.first+b.second;
            }
        };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> q;
        vector<vector<int>>res;

        for (int i=0; i<nums1.size(); ++i){
            for (int j=0; j<nums2.size(); ++j){
                if (q.size()<k) 
                    q.push({nums1[i], nums2[j]});
                else{
                    if (nums1[i]+nums2[j]<q.top().first+q.top().second){
                        q.pop();
                        q.push({nums1[i], nums2[j]});
                    }
                }
            }
        }

        while (!q.empty()){
            pair<int, int> top = q.top();
            res.push_back({top.first, top.second});
            q.pop();
        }
        return res;
    }
};
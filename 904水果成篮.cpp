class Solution{
    public:
        int totalFruit(vector<int>& tree){
            int n=tree.size();
            if (n==2) return n;
            int l = 0;
            int type1 = tree[l];
            int idx1 = l;
            while (idx1 < n && tree[idx1]==type1)
                idx1++;
            if (idx1==n)
                return n;
            
            int r = idx1;
            idx1--;
            int type2 = tree[r];
            int idx2 = r;
            int ans = -1;
            while (r<n){
                if (tree[r]==type1){
                    idx1 = r;
                    r++;
                }
                else if (tree[r] == type2){
                    idx2 = r;
                    r++;
                }
                else{
                    ans = max(ans, r-l);
                    if (tree[r-1]==type1)
                        l = idx2 + 1;
                    else{
                        l = idx1 + 1;
                        type1 = type2;
                        idx1 = idx2;
                    }
                    type2 = tree[r];
                    idx2 = r;
                }
            }
            ans = max(ans, r-l);
            return ans;
            
        }
};



class Solution {
public:
    vector<int> p;
    int find(int x){
        if (p[x] != x){
            p[x] = find(p[x]);
        }
        return p[x];
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;
        p = vector<int>(n + 1, 0);
        for (int i = 0; i <= n; ++i){
            p[i] = i;
        }
        int remain = 0;
        for (int i = 0; i < connections.size(); ++i){
            int x = connections[i][0];
            int y = connections[i][1];
            int px = find(x);
            int py = find(y);
            if (p[x] == p[y])
                remain++;
            p[px] = py;
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i){
            if (p[i] == i)
                cnt++;
        }
        if (remain >= (cnt - 1)){
            return cnt - 1;
        }
        else
            return -1;
    }
};
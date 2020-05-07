/*************************************************
每次将边界上最短的点找出，取其邻点，
1、若低于外围则可以蓄水，
然后边界内缩，刚才的边界删除，邻点作为新的边界，
但是边界高度需要改为刚才被删除的边界的高度。
2、若邻点高于这个最短的点，也是将最短点删除，
然后邻点作为新边界，但高度为邻点本身的高度。
3、继续下去，直到边界集合中没有点为止
*************************************************/
class Node{
public:
    int x, y, h;
    Node(int _x = 0, int _y = 0, int _h = 0):x(_x), y(_y), h(_h){}
    friend bool operator < (const Node& a, const Node& b){
        return a.h > b.h;
    }    
};

class Solution {
public:

    int R, C;
    int cd_x[4] = {-1, 0, 1, 0};
    int cd_y[4] = {0, -1, 0, 1};
    bool Judge(int x, int y){
        return x>0 && x<R && y>0 && y<C;
    }
    int trapRainWater(vector<vector<int>>& heightMap) {
        //若容器长或宽小于3x3，不可能接水
        if (heightMap.size()<3 || heightMap[0].size()<3) return 0;
        R = heightMap.size();
        C = heightMap[0].size();
        vector< vector<int> > vis(R, vector<int>(C));
        priority_queue<Node> pq;
        for (int i = 0; i<C; i++){
            vis[0][i] = vis[R-1][i] = 1;
            pq.push(Node(0, i, heightMap[0][i]));
            pq.push(Node(R-1, i, heightMap[R-1][i]));
        }
        for (int j = 0; j < R; j++){
            vis[j][0] = vis[j][C-1] = 1;
            pq.push(Node(j, 0, heightMap[j][0]));
            pq.push(Node(j, C - 1, heightMap[j][C - 1]));
        }

        int res = 0;
        while (!pq.empty()){
            //利用木桶原理， 每次将最小的边界找出，讨论情况
            Node cur = pq.top(); pq.pop();
            for (int i = 0; i < 4; ++i){
                int x = cur.x + cd_x[i];
                int y = cur.y + cd_y[i];
                if (Judge(x, y) && !vis[x][y]){
                    vis[x][y] = 1;
                    res += max(0, cur.h - heightMap[x][y]);
                    pq.push(Node(x, y, max(cur.h, heightMap[x][y])));
                }
            }
        }
        return res;
    }
};
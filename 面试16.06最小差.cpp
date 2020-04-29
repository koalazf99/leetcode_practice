// class Solution {
// public:
//     int smallestDifference(vector<int>& a, vector<int>& b) {
//         sort(a.begin(), a.end());
//         sort(b.begin(), b.end());
//         int i=0, j=0;
//         long long res=LLONG_MAX;
//         bool flag=false;
//         while  (i<a.size() && j<b.size()){
//             while (i<a.size() && j<b.size() && a[i]>=b[j]) {j++; flag=true;}
//             if (flag){
//                 res = (res>(long long)a[i]-(long long)b[j-1])?(long long)a[i]-(long long)b[j-1]:res;
//                 flag = !flag;
//             }
//             if (j==b.size()) return res;

//             while (i<a.size() && j<b.size() && a[i]<b[j]) {i++; flag=true;}
//             if (flag){
//                 res = (res>(long long)b[j]-(long long)a[i-1])?(long long)b[j]-(long long)a[i-1]:res;
//                 flag = !flag;
//             }
//             if (i==a.size()) return res;
//         }
//         return res;
//     }
// };
class Solution {
public:
    int smallestDifference(vector<int>& a, vector<int>& b) 
    {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        long ret = INT_MAX;
        for(int i = 0, j = 0; i < a.size() && j < b.size();)
        {
            ret = min(ret,abs(long(a[i])-long(b[j])));
            if(a[i] < b[j]){
                i++;
            }else{
                j++;
            }
        }
        return ret;
    }
};
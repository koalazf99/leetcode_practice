/*****************************************
在一个由 'L' , 'R' 和 'X' 三个字符组成的字符串（例如"RXXLRXRXL"）中进行移动操作。一次移动操作指用一个"LX"替换一个"XL"，或者用一个"XR"替换一个"RX"。现给定起始字符串start和结束字符串end，请编写代码，当且仅当存在一系列移动操作使得start可以转换成end时， 返回True。

L表示只能往左移
R表示智能往右移
只要end中所有的R都在对应start的R的右边
所有的L都在start的L的左边即可
*********************************************************/

class Solution {
public:
    bool canTransform(string start, string end) {
        int i=0, j=0;
        while (i<start.length() || j<end.length()){
            while (i < start.length() && start[i] == 'X') i++;
            while (j < end.length() && end[j] == 'X') j++;
            if (start[i] != end[j] ||
                (start[i] == 'L' && j > i) ||
                (start[i] == 'R' && j < i) ) return false;
            i++;
            j++;
        }
        return true;
    }
};
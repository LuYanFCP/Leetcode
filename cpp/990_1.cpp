#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
     * 提示：
     * 1. 1 <= equations.length <= 500
     * 2. equations[i].length == 4
     * 3. equations[i][0] 和 equations[i][3] 是小写字母
     * 4. equations[i][1] 要么是 '='，要么是 '!'
     * 5. equations[i][2] 是 '='
     */
    /**
     * 改进，使用数组代替之前用的hashmap， 增加并查集的路径压缩算法、。
     * 
     * 改进后：
     * 速度： 4 ms, 在所有 C++ 提交中击败了98.83%的用户。
     * 内存： 内存消耗 :10.8 MB, 在所有 C++ 提交中击败了50.00%的用户。  
    */

    bool equationsPossible(vector<string>& equations) {
        // 并查集初始化
        int set[30];
        for (int i = 0; i < 30; ++i) set[i] = i;
        for (const string &s : equations) {
            if (s[1] == '=') {
                join(set, s[0]-'a', s[3]-'a');
            }
        }
        for (const string &s : equations) {
            if (s[1] == '!') {
                if (find(set, s[0]-'a') == find(set, s[3]-'a'))
                    return false;
            }
        }
        return true;
    }

    
    char find(int *set, int x) {
        if (set[x] == x) return x;
        int res = find(set, set[x]);  // 路径压缩算法
        return res;
    }
    void join(int *set, int x, int y) {
        int root_x = find(set, x);
        int root_y = find(set, y);
        set[root_y] = root_x;
    }
};
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
     * 执行用时 :16 ms, 在所有 C++ 提交中击败了25.68%的用户
     * 内存消耗 :11.2 MB, 在所有 C++ 提交中击败了50.00%的用户
    */
    unordered_map<char, char> eq;

    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        
        for(const string &s: equations) { 
            bool flag1 = insert_node(eq, s[0]);
            bool flag2 = insert_node(eq, s[3]);  // 插入 
            if (s[1] == '=') join(eq, s[0], s[3]);
        }

        for(const string &s: equations) { 
            if (s[1] == '!') {
                char root1 = find(eq, s[0]);
                char root2 = find(eq, s[3]);
                if (root1 == root2) return false;
            }
        }

        return true;
    }

    bool is_exist(unordered_map<char, char>& set, char x) {
        return set.find(x) != set.end();
    }
    bool insert_node(unordered_map<char, char>& set, char x) {
        if (is_exist(set, x)) return false;
        set[x] = x; 
        return true;
    }
    char find(unordered_map<char, char>& set, char x) {
        if (set[x] == x) return x;
        return find(set, set[x]);
    }
    void join(unordered_map<char, char>& set, char x, char y) {
        char x_root = find(set, x);
        char y_root = find(set, y);
        set[y_root] = x_root;
    }
};
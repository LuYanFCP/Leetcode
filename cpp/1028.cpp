/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* build_tree(queue<pair<int, int>> &q, int depth) {
        if (q.empty() || q.front().second != depth) return nullptr;
        TreeNode* r = new TreeNode(q.front().first);
        q.pop();
        r->left = build_tree(q, depth+1);
        r->right = build_tree(q, depth+1);
        return r;
    }
    /**
     * 执行用时 :24 ms, 在所有 C++ 提交中击败了89.80%的用户
     * 内存消耗 :21.2 MB, 在所有 C++ 提交中击败了100.00%的用户
    */
    TreeNode* recoverFromPreorder(string S) {
        queue<pair<int, int>> q;
        S.push_back('-');  // 添加一个方便处理
        int count = 0, left = 0;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == '-') {
                if (left != i) {
                    q.push(pair<int, int>(atoi(S.substr(left, i - left).c_str()), count));
                    count = 0;
                }
                ++count;
                left = i+1;
            }
        }
        return build_tree(q, 0);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.recoverFromPreorder("1-401--349---90--88");
    return 0;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Definition for a binary tree node.
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int result = INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return result;
    }
    int dfs(TreeNode *r) {
        if(!r) return 0;
        int left_val = dfs(r->left);
        int right_val = dfs(r->right);
        result = max({result, r->val, r->val + left_val, r->val + right_val, r->val + left_val + right_val});
        return max({r->val, r->val + left_val, r->val + right_val});
    }
};
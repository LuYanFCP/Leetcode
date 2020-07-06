#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int max_depth;
    int diameterOfBinaryTree(TreeNode* root) {
        max_depth = 0;
        depth(root);
        return max_depth;
    }
    
    int depth(TreeNode* root) {
        if (!root) return 0;
        int left_depth = depth(root->left);
        int right_depth = depth(root->right);
        max_depth = max(max_depth, left_depth + right_depth);
        return max(left_depth, right_depth)+1;
    }
};
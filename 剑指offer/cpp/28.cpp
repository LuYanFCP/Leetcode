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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return is_curr(root->left, root->right);
    }
    bool is_curr(TreeNode* r1, TreeNode* r2) {
        if (!(r1 || r2)) return true; // 两个都是null
        if (!(r1 && r2) || (r1->val != r2->val)) return false;
        return is_curr(r1->left, r2->right) && is_curr(r1->right, r2->left);
    }

};
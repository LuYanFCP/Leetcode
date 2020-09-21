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
    TreeNode* convertBST(TreeNode* root) {
        int _sum = 0;
        order(root, _sum);
        return root;
    }
    void order(TreeNode* root, int& _sum) {
        if (root == nullptr) return;
        order(root->right, _sum);
        _sum += root->val;
        root->val = _sum;
        order(root->left, _sum);
    }
};
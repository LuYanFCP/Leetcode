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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        dfs(root, 1, sum);
        return sum;
    }
    void dfs(TreeNode* root, int flag, int& sum) {
        // flag 0 左 1 右
        if (root->left == nullptr && root->right == nullptr) {
            if (flag == 0) sum += root->val;
            return;
        }
        if (root->left != nullptr) dfs(root->left, 0, sum);
        if (root->right != nullptr) dfs(root->right, 1, sum);

    }
};
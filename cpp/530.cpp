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
    int min_diff;
    int pre_diff;
    int getMinimumDifference(TreeNode* root) {
        this->min_diff = INT_MAX;
        this->pre_diff = -100000000;
        inorder(root);
        return min_diff;
    }
    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder(root->left);

        if ((root->val - pre_diff) < min_diff) 
            min_diff = root->val - pre_diff;
        pre_diff = root->val;
        
        inorder(root->right);
    }
};
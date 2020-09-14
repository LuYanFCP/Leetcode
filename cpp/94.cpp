#include<bits/stdc++.h>

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<TreeNode*> stack;
        vector<int> res;
        TreeNode* q = root;
        while (q || stack.size() != 0) {
            while (q) {
                stack.push_back(q);
                q = q->left;
            }
            if (stack.size()) {
                q = stack.back();
                res.push_back(q->val);
                q = q->right;
                stack.pop_back();
            }
        }
        return res;
    }
};
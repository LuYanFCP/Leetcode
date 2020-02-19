#include <vector>
#include <iostream>
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* 16 ms 69.96%	
 * 20 MB 50.00%
 */
class Solution {
public:
    vector<vector<int>> res;
    int sum;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> stack;
        this->sum = sum;
        order(root, stack, 0);
        return res;
    }
    void order(TreeNode* root, vector<int>& stack,int sum) {
        if (root != nullptr) {
            stack.push_back(root->val);
            sum += root->val;
            if (root->left || root->right) {  // 是否是根节点
                order(root->left, stack, sum);
                order(root->right, stack, sum);
            } else {
                if (sum == this->sum) {
                    this->res.push_back(stack);  // push_back为拷贝操作
                }
            }
            stack.pop_back();
        }
    }
};
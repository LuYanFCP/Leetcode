#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return generateTrees(1,n);
    }
    
    vector<TreeNode*> generateTrees(int begin, int end) {
        
        vector<TreeNode*> ans;
        if(begin > end) return {nullptr}; // 返回， 边界条件
        // 递归代码
        for(int i=begin; i<=end; i++) {  // 将任意作为中心
            for(auto& l : generateTrees(begin, i-1)) {  // 前半部分
                for(auto& r : generateTrees(i+1, end)) { // 后半部分
                    TreeNode* root = new TreeNode(i,l,r);
                    ans.push_back(root);
                }
            }            
        }
        return ans;
    }  
};
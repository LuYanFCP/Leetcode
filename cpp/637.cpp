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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        map<int, pair<int64_t, int>> dict; // key-> depth, pair-> first:sum, second = count; , warning 这里会用溢出条件恶心人，小心int32, 又没办法用u_int32_t, 只能用int64
        q.emplace(root, 1);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            TreeNode* node_ptr = node.first;
            int depth = node.second;
            auto end_ptr = dict.end();
            if (dict.find(depth) != end_ptr) {  // 说明有
                dict[depth].first += node_ptr->val;
                dict[depth].second++;
            } else {
                dict[depth] = {node_ptr->val, 1};    // 说明没有
            }
            if (node_ptr->left) q.emplace(node_ptr->left, depth+1);
            if (node_ptr->right) q.emplace(node_ptr->right, depth+1);
        }
        vector<double> res;
        transform(dict.begin(), dict.end(), back_inserter(res), 
            [](const pair<int, pair<int64_t, int>> & x) { return x.second.first * 1.0 / x.second.second;});
        return res;
    }
};

int main()
{
    return 0;
}
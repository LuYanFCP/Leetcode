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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> res;
        vector<string> st;
        dfs(root, st, res);
        return res;
    }
    void dfs(TreeNode *root, vector<string>& st, vector<string>& res)
    {
        st.emplace_back(to_string(root->val));
        st.emplace_back("->");
        if (!(root->left || root->right))  //叶子节点
        {
            st.pop_back(); // 把 -> 吐出来
            stringstream temp;
            for (string& s: st) temp << s;
            // cout << temp.str() << endl;
            res.emplace_back(temp.str());
            st.pop_back();
            return;
        }
        if (root->left) dfs(root->left, st, res);
        if (root->right) dfs(root->right, st, res);
        st.pop_back();
        st.pop_back();
    }
};
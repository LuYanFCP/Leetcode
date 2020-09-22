#include <bits/stdc++.h>
using namespace std;

struct Status
{
    int a, b, c;
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int minCameraCover(TreeNode* root) {
        auto [a, b, c] = dfs(root);
        return b;
    }

    Status dfs(TreeNode* root) {
        if (root == nullptr) {
            return {INT_MAX/2, 0, 0};
        }
        auto [la, lb, lc] = dfs(root->left);
        auto [ra, rb, rc] = dfs(root->right);
        int a = lc + rc + 1;
        int b = min(a, min(la+rb, ra+lb));  // 
        int c = min(a, lb+rb);
        return {a, b, c};
    }
};



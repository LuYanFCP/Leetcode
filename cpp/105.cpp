#include <vector>
#include <algorithm>
using std::find;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/**
  * time: 20 ms
  * Memory: 22.3 MB 
  */

class Solution {
public:
    TreeNode* 
    buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() != 0) {
            auto p_begin = preorder.begin();
            TreeNode* rs = pi2T(p_begin, inorder.begin(), inorder.end());
            return rs;
        }
        return nullptr;
    }

    TreeNode*
    pi2T(vector<int>::const_iterator &p_begin,  vector<int>::const_iterator i_begin, vector<int>::const_iterator i_end) {
        if (i_begin != i_end) {
            int val = *p_begin;
            p_begin++; // 向后走
            auto mid = find(i_begin, i_end, val);
            TreeNode* node = new TreeNode(val);
            node->left = pi2T(p_begin, i_begin, mid);
            node->right = pi2T(p_begin, mid+1, i_end);
            return node;
        }
        return nullptr;
    }
};


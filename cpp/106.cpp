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
    buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (0 != inorder.size()) {
            auto p_rbegin = postorder.rbegin();
            TreeNode* rs = ip2T(p_rbegin, inorder.cbegin(), inorder.cend());
            return rs;
        }
        return nullptr;
    }

    TreeNode*
    ip2T(vector<int>::reverse_iterator &p_rbegin,  vector<int>::const_iterator i_begin, vector<int>::const_iterator i_end) {
        if (i_begin != i_end) {
            int val = *p_rbegin;
            p_rbegin++; // 向前
            auto mid = find(i_begin, i_end, val);
            TreeNode* node = new TreeNode(val);
            node->right = ip2T(p_rbegin, mid+1, i_end);
            node->left = ip2T(p_rbegin, i_begin, mid);
            return node;
        }
        return nullptr;
    }
};


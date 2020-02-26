/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildAVL(nums, 0, nums.size() - 1);
    }

    TreeNode* buildAVL(vector<int>& nums, int i, int j) {
    /*
     * 28 ms, faster than 51.03%
     * 25.1 MB, less than 16.22%
     * 
     */
        if (j < i)
            return nullptr;
        int mid = (j - i) / 2 + i;
        TreeNode* tempNode = new TreeNode(nums[mid]);
        tempNode->left = buildAVL(nums, i, mid - 1);
        tempNode->right = buildAVL(nums, mid + 1, j);
        return tempNode;
    }
};
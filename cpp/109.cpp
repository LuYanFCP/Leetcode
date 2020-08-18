#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Definition for a binary tree node.
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
    TreeNode* sortedListToBST(ListNode* head) {
        /* 链表 */
        vector<int> vec;
        ListNode* p = head;
        /**
         *  可以使用快慢节点去寻找链表的中点。
        */
        while (p) {
            vec.push_back(p->val);
            p = p->next;
        }
        return buildTree(vec, 0, vec.size()-1);
    }
    TreeNode* buildTree(vector<int> &vec, int l, int r) {
        if (r>l) return nullptr;
        int mid = (r-l)/2 + l;
        TreeNode* n = new TreeNode(vec[mid]);
        n->left = buildTree(vec, l, mid-1);
        n->right = buildTree(vec, mid+1, r);
        return n;
    }
};
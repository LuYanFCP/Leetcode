/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};
/*
 * 这个超过了88%
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0; // 进位
        ListNode* head = new ListNode(-1); // 创建一个head，这样就不会因为是不是第一个而多判断了
        ListNode* curr = head;
        while (l1 || l2) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry) curr->next = new ListNode(1);
        return head->next; // 丢弃头部
    }

    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
        /**
         * O(1)空间复杂度，但是会破坏l1和l2
        */
        ListNode* pos1 = l1, *pos2 = l2, *pre=nullptr;
        int add_flag = 0, sum;
        while(pos1 && pos2) {
            sum = pos1->val + pos2->val + add_flag;
            // 1和0
            if (sum >= 10) add_flag = 1;
            else add_flag = 0;
            pos1->val = sum % 10;
            pre = pos1;
            pos1 = pos1->next;
            pos2 = pos2->next;
        }
        if (pos2) { // 如果l2证明
            pre->next = pos2;
            pos1 = pos2;
        }
        while (pos1) {
            sum = pos1->val + add_flag;
            if (sum >= 10) add_flag = 1;
            else add_flag = 0;
            pre = pos1;
            pos1->val = sum % 10;
            pos1 = pos1->next;
        }
        if (add_flag) {
            pre->next = new ListNode(add_flag);
        }
        return l1;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <bits/stdc++.h>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
public:
    bool hashtable[20001] = {false};
    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode* begin = new ListNode(0);
        begin->next = head;
        
        while (begin->next) {
            if (!hashtable[begin->next->val]) {
                hashtable[begin->next->val] = true;
                begin = begin->next;
            } else {
                // printf("%d\n", hashtable[begin->next->val]);
                ListNode* temp = begin->next;
                begin->next = begin->next->next;
                delete temp;
            }

        }
        return head;
    }
    ListNode* removeDuplicateNodes2(ListNode* head) {
        ListNode* begin = head;
        while (begin) {
            ListNode* next_head = begin;
            while (next_head->next) { // 下一个，注意
                if (begin->val == next_head->next->val)
                    next_head->next = next_head->next->next;
                else
                    next_head = next_head->next;
            }
            begin = begin->next;
        }
        return head;
    }
};
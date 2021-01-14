# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        """
        递归
        """
        if head == None or head.next == None:
            return head
        p = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return p


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        """
        迭代
        """
        final_list = None
        while head:
            temp = head.next
            head.next = final_list
            final_list = head
            head = temp
        return final_list 
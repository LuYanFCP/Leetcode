# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

def swap(head: ListNode):
        final_list = None
        while head:
            temp = head.next
            head.next = final_list
            final_list = head
            head = temp

        return final_list 

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if k == 1 or head == None:
            return head

        end = head
        for _ in range(k-1):
            end = end.next  # 向后的
            if end == None:
                return head
        end_next = end.next
        end.next = None  # 放空
        # 交换一下
        swap(head)
        # 拼起来
        head.next = self.reverseKGroup(end_next, k)
        return end
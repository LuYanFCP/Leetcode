    # 链表交换专题



    ## 1. 基础，一个单链表的交换

    这里以[Leetcode 206](https://leetcode-cn.com/problems/reverse-linked-list/) 为例子. 

    > 206.反转链表
    > 反转一个单链表。
    > 
    > 示例:
    > 
    > 输入: 1->2->3->4->5->NULL
    > 输出: 5->4->3->2->1->NULL
    > 进阶:
    > 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
    > 版权由Leetcode所有，如有侵权，请联系删除

    也是一个很基础的模板

    首先说第一种思想：直接使用迭代，然后用头插法的方式，再将所有的Node插入新链表中，因为头插法是反向插入的，因此会起到反转的效果

    这种的思路也很简单

    1. 创建一个None做链表头。
    2. 迭代当前链表，将当前链表的Node插入新链表。

    ```python
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
    ```
    其中`final_list`是新链表的head位置，初始为NULL，然后使用一个`while`循环去迭代，当前的链表`head`，然后使用头插法一步一步的将Node插入。

    递归：

    递归的思路主要集中在：
    1. `reverseList` 将`head.next`部分的链表反转，例如要反转的链表是`[1,2,3,4]`, 首先先将`[2,3,4]`进行反转为`[4, 3, 2]`
    2. 将`head`放在最后，例如： 然后将`[1]`放在`[4, 3, 2]`的后面`[4,3,2,1]`

    > note: 这个思路有一个问题：如何找到2能捕获2的指针从而完成操作`2->next = 1`，最简单的思路是直接去遍历，但是很浪费事件，这里可以直接采用递归体中，先对后面的进行反转，然后再拼接前半部分的顺序，此时`[1]`的next其实依旧指向`[2]`，因此我们可以直接这样捕获，避免重新去查找。

    形成代码

    ```python

    class Solution:
        def reverseList(self, head: ListNode) -> ListNode:
            if head == None or head.next == None:  # 防止出现None指针操作
                return head
            p = self.reverseList(head.next)
            head.next.next = head
            head.next = None
            return p
    ```

    ## 2. 进一步提升，如果要两两替换呢？

    这里使用[Leetcode 24](https://leetcode-cn.com/problems/swap-nodes-in-pairs/)来说明这个问题。

    > 24.两两交换链表中的节点
    > 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
    > 
    > 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
    ![](./swap_ex1.jpg)
    >
    > 输入：head = [1,2,3,4]
    > 输出：[2,1,4,3]
    > 示例 2：
    >
    > 输入：head = []
    > 输出：[]
    > 示例 3：
    > 
    > 输入：head = [1]
    > 输出：[1]
    >  
    > 提示：
    > 
    > 链表中节点的数目在范围 [0, 100] 内
    > 0 <= Node.val <= 100
    >
    > 来源：力扣（LeetCode）
    > 链接：https://leetcode-cn.com/problems/swap-nodes-in-pairs 
    > 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    这个依旧分为两个思路：迭代和递归

    迭代：向后移动两个指针然后交换

    迭代这里给两个版本
    1. 需要使用指针的指针进行操作，因为需要获取到两个节点中前一个节点中的前一个节点的指针，在`python`中一般使用一个临时节点来充当指针的指针例如很多题解中的`dummy = ListNode(-1)`，另一方面也是增加一个头节点方便操作。如果是`C/C++`即可直接使用`**ListNode`
    ```python
    class Solution:
        def swapPairs(self, head: ListNode) -> ListNode:
            head_pointer = ListNode(-1) # 指针的指针，头节点
            pre = head_pointer 
            pre.next = head
            first, second = None, None  # 两个节点中的第一个节点和第二个节点
            while head and head.next:   # next 为 null即可退出
                first = head
                second = head.next
                pre.next = second       #交换两节点
                first.next = second.next
                second.next = first

                pre = first             #继续遍历后续节点
                head = first.next
            return head_pointer.next

    ```
    2. 直接进行值交换
    ```python
    class Solution:
        def swapPairs(self, head: ListNode) -> ListNode:
            if head == None:
                return head
            
            first, second = head, head.next
            while second != None:
                first.val, second.val = second.val, first.val

                first = second.next
                if first == None:
                    break
                second = first.next
            
            return head
    ```

    递归：向前移动两个指针，先将后半部分交换，再将当前位置交换，然后拼接.

    ```python
    class Solution:
        def swapPairs(self, head: ListNode) -> ListNode:
            if head == None or head.next == None:
                return head
            next_node = head.next
            head.next = self.swapPairs(next_node.next)
            next_node.next = head
            return next_node
    ```


    ## 3. 任意顺序的K个节点交换

    这里使用，[Leetcode25 K个一组翻转链表](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/)作为例子。


    由于K个交换过于复杂，这里没有采用迭代的思路，因为迭代的思路需要使用栈存储便利后的一些节点。使用递归思路和代码都比较简答。

    首先将问题分为两个部分：
    1. K个节点如何交换。这个其实可以转化为问题1，直接套用问题一的模板即可。
    2. 判断k个节点的范围。

    ```python

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
            # 向后找k个节点
            for _ in range(k-1):
                end = end.next  # 向后的
                if end == None:
                    return head
            end_next = end.next
            # end之后置空，方便swap函数进行判断
            end.next = None
            # 交换一下
            swap(head)
            # 拼起来
            head.next = self.reverseKGroup(end_next, k)
    ```

    时间复杂度为`O(n)`刚好扫描过所有的链表。空间复杂度由于是递归的问题存在一定的递归栈空间复杂度是`O(n/k)`
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if (list1 == None):
            return list2
        if list2 == None:
            return list1

        node = ListNode(-1)

        '''if (list1.val < list2.val):
            node = ListNode(list1.val)
            list1 = list1.next
        else:
            node = ListNode(list2.val)
            list2 = list2.next'''

        node1 = node

        while (list1!= None and list2!= None):
            if (list1.val < list2.val):
                node.next = ListNode(list1.val)
                list1 = list1.next
            else:
                node.next = ListNode(list2.val)
                list2 = list2.next
            node = node.next

        while (list1 != None):
            node.next = ListNode(list1.val)
            list1 = list1.next
            node = node.next

        while (list2 != None):
            node.next = ListNode(list2.val)
            list2 = list2.next
            node = node.next

        return node1.next
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        count = 0
        
        head1 = head
        
        while head1:
            count += 1
            head1 = head1.next
            
        # print (count)
            
        if n == count:
            return head.next
        
        count2 = 0
        
        head2 = head
        
        while head2:
            count2 += 1
            # print(count2)
            if (count2 == count - n):
                head2.next = head2.next.next
                return head
            head2 = head2.next
        
        return head
            
        
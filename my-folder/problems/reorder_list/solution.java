/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public void reorderList(ListNode head) {
        ListNode p1 = head;
        ListNode p2 = head;

        while (p2.next != null && p2.next.next!= null){
            p1 = p1.next;
            p2 = p2.next.next;
        }

        ListNode premid = p1;
        ListNode nextmid = p1.next;
        
        ListNode prev = null;
        ListNode curr = nextmid;

        while (curr != null){
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }

        premid.next = null;

        ListNode head2 = prev;

        while (head2 != null){
            ListNode next1 = head.next;
            ListNode next2 = head2.next;

            head.next = head2;
            head2.next = next1;
            head = next1;
            head2 = next2;
        }
    }
}
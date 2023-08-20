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
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) return null;

        PriorityQueue<ListNode> pq = new PriorityQueue<ListNode>(lists.length, new Comparator<ListNode>(){
            @Override
            public int compare(ListNode n1, ListNode n2){
                if (n1.val < n2.val) return -1;
                else if (n1.val == n2.val) return 0;
                else return 1;
            }
        });

        for (ListNode n: lists){
            if (n != null) pq.add(n);
        }

        ListNode head = new ListNode(0);
        ListNode temp = head;

        while (!pq.isEmpty()){
            temp.next = pq.poll();
            temp = temp.next;

            if (temp.next != null) pq.add(temp.next);
        }

        return head.next;
    }
}
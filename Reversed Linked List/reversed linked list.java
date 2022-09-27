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
    public ListNode newHead = null;
    public ListNode reverseList(ListNode head) {
       if (head != null) {
           ListNode lastNode = reverse(head);
           lastNode.next = null;
       }
        return newHead;
    }
    
    public ListNode reverse(ListNode current) {
        if (current.next == null) {
            newHead = current;
            return current;
        }
        else {
            ListNode lastNode = reverse(current.next);
            lastNode.next = current;
            return current;
        }
    }
    
}
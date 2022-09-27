/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) {
            return false;
        }
        
        ListNode first = head, second = head;
        
        do {
            first = first.next;
            second = second.next.next;
            
            if (first == second) {
                return true;
            }
            
        } while (first != null && second != null && second.next != null);
        
        return false;
    }
}
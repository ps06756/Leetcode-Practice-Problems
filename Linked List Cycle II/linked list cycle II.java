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
    public ListNode detectCycle(ListNode head) {
        ListNode slow = head, fast = head;
        ListNode insPoint = null;
        
        while (true) {
            if (fast == null || fast.next == null) {
                return null;
            }
            slow = slow.next;
            fast = fast.next.next;
            
            if (slow == fast) {
                insPoint = slow;
                break;
            }
        }
        
        ListNode start = head;
        while (start != insPoint) {
            start = start.next;
            insPoint = insPoint.next;
        }
        
        return start;
    }
}
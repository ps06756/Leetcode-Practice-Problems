/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        int m = findLength(headA);
        int n = findLength(headB);
        ListNode fp = null, sp = null;
        if (m <= n) {
            fp = headA;
            sp = headB;
            for(int i = 0; i < n - m; i++) {
                sp = sp.next;
            }
        }
        else {
            fp = headA;
            sp = headB;
            for(int i = 0; i < m - n; i++) {
                fp = fp.next;
            }
        }
        
        while (fp != null) {
            if (fp == sp) {
                return fp;
            }
            fp = fp.next;
            sp = sp.next;
        }
        
        return null;
    }
    
    public int findLength(ListNode head) {
        int length = 0;
        ListNode curr = head;
        while (curr != null) {
            curr = curr.next;
            length++;
        }
        return length;
    }
}
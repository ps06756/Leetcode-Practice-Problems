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
    public boolean isPalindrome(ListNode head) {
        int n = findLength(head);
        if (head.next == null) {
            return true;
        }
        int reversePoint = n/2;
        if (n%2 == 1) {
            reversePoint = (n/2) + 1;
        }
        
        ListNode head2 = findNodeAtPosition(head, reversePoint);
        ListNode prev = findNodeAtPosition(head, reversePoint - 1);
        
        reverse(head2, prev);
        
        ListNode first = head;
        ListNode second = prev.next;
        
        while (first != null && second != null) {
            if (first.val != second.val) {
                return false;
            }
            first = first.next;
            second = second.next;
        }
        
        return true;
    }
    
    
    int findLength(ListNode head) {
        int length = 0;
        ListNode curr = head;
        while (curr != null) {
            length++;
            curr = curr.next;
        }
        return length;
    }
    
    ListNode findNodeAtPosition(ListNode head, int pos) {
        int count = 0;
        ListNode curr = head;
        while (count < pos) {
            count++;
            curr = curr.next;
        }
        return curr;
    }
    
    void reverse(ListNode head, ListNode prev) {
        ListNode a = head;
        ListNode b = head.next;
        
        while (a != null && b != null) {
            ListNode temp = b.next;
            b.next = a;
            a = b;
            b = temp;
        }
        prev.next = a;
        head.next = null;
    }
}
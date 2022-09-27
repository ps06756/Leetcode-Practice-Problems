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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode first = list1, second = list2;
        ListNode head = null, tail = null;
        while (first != null || second != null) {
            ListNode nodeToCopy = null;
            if (first != null && second != null) {
                if (first.val < second.val) {
                    nodeToCopy = first;
                    first = first.next;
                }
                else {
                    nodeToCopy = second;
                    second = second.next;
                }
            }
            else if (first != null) {
                nodeToCopy = first;
                first = first.next;
            }
            else {
                nodeToCopy = second;
                second = second.next;
            }
            
            tail = insert(tail, nodeToCopy.val);
            if (head == null)  {
                head = tail;
            }
            
        }
        
        return head;
        
    }
    
    public ListNode insert(ListNode tail, int data) {
        ListNode ntbi = new ListNode(data, null);
        
        if (tail != null) {
            tail.next = ntbi;
        }
        
        return ntbi;
    }
}
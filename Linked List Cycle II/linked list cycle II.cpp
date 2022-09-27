/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode *slow = head, *fast = head;
        ListNode *insPoint = NULL;
        
        while (true) {
            if (fast == NULL || fast->next == NULL) {
                return NULL;
            }
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                insPoint = slow;
                break;
            }
        }
        
        ListNode *start = head;
        while (start != insPoint) {
            start = start->next;
            insPoint = insPoint->next;
        }
        
        return start;
    }
};
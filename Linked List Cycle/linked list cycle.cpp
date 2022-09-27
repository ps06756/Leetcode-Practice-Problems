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
    bool hasCycle(ListNode *head) {
        ListNode *first = head, *second = head;
        if (head == NULL || head->next == NULL) {
            return false;
        }
        do {
            first = first->next;
            second = second->next->next;
            if (first == second) {
                return true;
            }
            
        } while (first != NULL && second != NULL && second->next != NULL);
        
        return false;
    }
};
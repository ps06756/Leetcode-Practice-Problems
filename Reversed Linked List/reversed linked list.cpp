/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *newHead = NULL;
    ListNode* reverseList(ListNode* head) {
        if (head != NULL) {
            ListNode *lastNode = reverse(head);
            lastNode->next = NULL;
        }
        return newHead;
    }
    
    ListNode* reverse(ListNode *current) {
        if (current->next == NULL) {
            newHead = current;
            return current;
        }
        else {
            ListNode *lastNode = reverse(current->next);
            lastNode->next = current;
            return current;
        }
    }
};
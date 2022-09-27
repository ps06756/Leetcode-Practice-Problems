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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m = findLength(headA);
        int n = findLength(headB);
        ListNode *fp = headA, *sp = headB;
        if (m <= n) {
            for(int i = 0; i < n - m; i++) {
                sp = sp->next;
            }
        }
        else {
            for(int i = 0; i < m - n; i++) {
                fp = fp->next;
            }
        }
        while (fp != NULL) {
            if (sp == fp) {
                return fp;
            }
            sp = sp->next;
            fp = fp->next;
        }
        return NULL;
    }
    
    int findLength(ListNode *head) {
        int length = 0;
        ListNode *curr = head;
        while (curr != NULL) {
            curr = curr->next;
            length++;
        }
        return length;
    }
};
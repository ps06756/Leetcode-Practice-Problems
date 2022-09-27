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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *first = list1, *second = list2;
        ListNode *head = NULL, *tail = NULL;
        
        while (first != NULL || second != NULL) {
            if (first != NULL && second != NULL) {
                if (first->val < second->val) {
                    tail = addAtTheEnd(tail, first->val);
                    first = first->next;
                }
                else {
                    tail = addAtTheEnd(tail, second->val);
                    second = second->next;
                }
            }
            else if (first != NULL) {
                tail = addAtTheEnd(tail, first->val);  
                first = first->next;
            }
            else {
                tail = addAtTheEnd(tail, second->val);
                second = second->next;
            }
            
            if (head == NULL) {
                head = tail;
            }
        }
        
        return head;
    }
    
    ListNode* addAtTheEnd(ListNode *tail, int data) {
        ListNode *ntbi = new ListNode;
        ntbi->val = data;
        ntbi->next = NULL;
        
        if (tail != NULL) {
            tail->next = ntbi;
        }
        return ntbi;
    }
};
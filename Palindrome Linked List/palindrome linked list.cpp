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
    bool isPalindrome(ListNode* head) {
        int n = findLength(head);
        if (n == 1) {
            return true;
        }
        int reversePoint = n/2;
        if (n%2 == 1) {
            reversePoint = (n/2) + 1;
        }
        
        ListNode *head2 = findNode(head, reversePoint);
        ListNode *prev = findNode(head, reversePoint - 1);
        reverse(head2, prev);
        ListNode *first = head;
        ListNode *second = findNode(head, reversePoint);
        
        while (first != NULL && second != NULL) {
            if (first->val != second->val) {
                return false;
            }
            first = first->next;
            second = second->next;
        }
        return true;
       
    }
               
    int findLength(ListNode *head) {
        int length = 0;
        ListNode *current = head;
        while (current != NULL) {
            length++;
            current = current->next;
        }
        return length;
    }   
    
    ListNode *findNode(ListNode *head, int index) {
        int count = 0;
        ListNode *current = head;
        
        while (count < index) {
            current = current->next;
            count++;
        }
        
        return current;
    }
    
    ListNode *reverse(ListNode *head, ListNode *prev) {
        ListNode *a = head;
        ListNode *b = a->next;
        while (a != NULL && b != NULL) {
            ListNode *temp = b->next;
            b->next = a;
            a = b;
            b = temp;
        }
        
        prev->next = a;
        head->next = NULL;
        return prev;
    }
};
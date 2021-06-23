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
    ListNode* reverseBetween(ListNode* head, int left1, int right1) {
        
        if (head == NULL) return NULL;
        ListNode *prevLeft = NULL;
        ListNode *left = head;
        ListNode *right = head;
        ListNode *afterRight = NULL;
        
        int cnt = 1;
        while (cnt < left1) {
            prevLeft = left;
            left = left -> next;
            right = right -> next;
            cnt++;
        }
        while (cnt < right1) {
            right = right -> next;
            cnt++;
        }
        afterRight = right->next;
        ListNode *prev = NULL;
        ListNode *cur = left;
        ListNode *nxt = NULL;
        while (cur != afterRight) {
            
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        if (prevLeft != NULL) {
            prevLeft->next = prev; 
        }
        left->next = afterRight;
        if (left == head) return prev;
        return head;
    }
};
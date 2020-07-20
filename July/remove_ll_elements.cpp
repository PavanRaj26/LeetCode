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
    ListNode* removeElements(ListNode* head, int val) {
          int cnt = 0;
         ListNode* ptr = head;
         vector<int> v;
       if (head == NULL) return NULL;
        while(ptr != NULL) {
            if (ptr->val != val) {
                v.push_back(ptr->val);                
            }
            ptr = ptr->next;
        }
        ListNode *head1;
        int n = v.size();
        ListNode *prev = NULL;
        
        for (int i = 0; i < n; i++) {
            
            ListNode *cur = new ListNode(v[i]);
            if (prev != NULL) {
                prev->next = cur;
            }
            else {
                head1 = cur;                
            }
            prev = cur;            
        }
        return head1;
    }
};

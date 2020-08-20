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
    private:
    ListNode *root = NULL;
public:
    void recur(ListNode *cur,ListNode* prev) {
        
        if (cur == NULL || root == NULL) {
            return ;
        }        
        recur(cur->next,cur);
        if (prev != root && root != NULL && root != cur) {
            if (prev != NULL) {
                prev->next = NULL;
            }
            ListNode *next = root->next;
            if (cur != NULL) {
                root->next = cur;
                cur->next = next;
            }
            root = next;
        } else {
            root = NULL;
        }        
    }
    void reorderList(ListNode* head) {
        root = head;
        recur(head,NULL);
    }
};

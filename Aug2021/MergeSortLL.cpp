#include <stdio.h>

//Preorder
//Inorder

Node *merge(Node *a,Node *b) {
    
}
void middle(Node **a,Node **b, Node *head) {
    Node *slow= head;
    Node *fast = head->next;
    
    while (slow != NULL && fast != NULL) {
        slow=slow->next;
        fast = fast->next;
        if (fast) {
            fast = fast->next;
        }    
    }
    *b = slow->next;
    slow->next = NULL;
    *a = head;
    
}
void mergeSort(Node **headRef) {
    Node *head = *headRef;
    if (head == NULL || head->next == NULL) return;
    Node *a;
    Node *b;
    middle(&a,&b,head);
    mergeSort(&a);
    mergeSort(&b);
    Node *res = merge(a,b);
}

int main() {
	//code
	
	return 0;
}
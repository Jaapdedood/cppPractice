#include <iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};

void printList(ListNode* n){
    while (n != nullptr){
        std::cout << n->val <<" ";
        n = n->next;
    }
    std::cout << '\n';
}

void addNode(ListNode **head, int n){
    ListNode *newNode = new ListNode(n);
    newNode->next = *head;
    *head = newNode;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* result;
        return result;
    }
};

int main(){
    ListNode* head = new ListNode(4);
    addNode(&head, 2);
    addNode(&head, 1);
    
    ListNode* head2 = new ListNode(4);
    addNode(&head2, 3);
    addNode(&head2, 1);

    printList(head);
    printList(head2);

    return 0;
}
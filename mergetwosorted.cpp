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
        ListNode* temp = new ListNode(-1);
        ListNode* result = temp;

        while(l1 != nullptr && l2 != nullptr){
            if(l1->val < l2->val){
                temp->next = l1;
                l1 = l1->next;
            }
            else{
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }

        if(l1 != nullptr){
            temp->next = l1;
        }
        else{
            temp->next = l2;
        }

        return result->next;
    }
};

int main(){
    Solution solution;

    ListNode* head1 = new ListNode(4);
    addNode(&head1, 2);
    addNode(&head1, 1);
    
    ListNode* head2 = new ListNode(4);
    addNode(&head2, 3);
    addNode(&head2, 1);

    printList(head1);
    printList(head2);

    ListNode* merged = solution.mergeTwoLists(head1, head2);

    printList(merged);

    return 0;
}
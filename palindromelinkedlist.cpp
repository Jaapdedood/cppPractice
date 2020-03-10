#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    //ListNode(int x) : val(x), next(NULL) {}
 };
 
 void printList(ListNode* n){
    while (n != nullptr){
        std::cout << n->val <<" ";
        n = n->next;
    }
    std::cout << '\n';
}

void appendNode(ListNode* head, int value){
    ListNode* new_node = new ListNode;
    ListNode* last = head;

    new_node->val = value;
    new_node->next = nullptr;

    if(head == nullptr){
        std::cout << "fuck it \n";
    }
    else{
        while(last->next != nullptr){
            last = last->next;
        }
        last->next = new_node;
        return;
    }
}

ListNode* reverseList(ListNode* head) {
    // reverse half
    ListNode* prev = nullptr;
    ListNode* next = nullptr;

    while(head != nullptr){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // Find the middle of this list
        ListNode* slow = head;
        ListNode* fast = head;
        while((fast->next != nullptr) && (fast->next->next != nullptr)){
            slow = slow->next;
            fast = fast->next->next;
        }

        slow = reverseList(slow);

        while(head != nullptr){
            if(head->val != slow->val){
                return 0;
            }
            head = head->next;
            slow = slow->next;
        }
        return 1;
    }
};

int main() {
    Solution solution;

    ListNode* head = new ListNode;
    head->val = 1;
    head->next = nullptr;

    //printList(head);
    appendNode(head,5);
    appendNode(head,3);
    appendNode(head,5);
    appendNode(head,1);
    //appendNode(head,2);
    printList(head);
    std::cout << solution.isPalindrome(head) << "\n";

    return 0;
}
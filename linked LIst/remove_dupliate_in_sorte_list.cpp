#include<iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* deleteDuplicates(ListNode* A) {
    if(A == nullptr || A->next == nullptr) return A;
    ListNode* newList = A;
    ListNode* curr = A->next;
    
    while(curr) {
        if(newList->val == curr->val) {
            ListNode* temp = curr;
            curr = curr->next;
            delete temp;
        }else {
            newList->next = curr;
            newList = curr;
            curr = curr->next;
        }
    }
    
    newList->next = nullptr;
    return A;
}


void print(ListNode *head) {
    while(head) {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}


int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);

    print(head);

    head = deleteDuplicates(head);

    print(head);

}
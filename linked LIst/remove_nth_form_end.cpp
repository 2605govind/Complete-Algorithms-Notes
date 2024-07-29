#include<iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

 
int findSizeOfList(ListNode* head) {
    int count = 0;
    while(head) {
        count++;
        head = head->next;
    }
    return count;
}

ListNode* removeNthFromEnd(ListNode* A, int B) {
    
    
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
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    print(head);

    head = removeNthFromEnd(head,4);

    print(head);

}
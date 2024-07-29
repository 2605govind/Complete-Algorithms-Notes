#include<iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


int sizeOfList(ListNode* head) {
    int count = 0;
    while(head) {
        count++;
        head = head->next;
    }

    return count;
}

ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    
    while(head) {
        ListNode* temp = head->next;
        head->next = prev;
        prev = head;
        
        head = temp;
    }
    
    return prev;
}

ListNode* findMiddle(ListNode* head) {
    ListNode *first = head;
    ListNode *second = head->next;
    
    while(second && second->next) {
        second = second->next->next;
        first = first->next;
    }
    
    return first;
}

int lPalin(ListNode* A) {
    int size = sizeOfList(A);
    
    ListNode* middle = findMiddle(A);
    
    ListNode* list1 = A;
    ListNode* list2 = middle->next;
    
    middle->next = nullptr;
    
    list1 = reverse(list1);
    
    ListNode* curr1 = list1;
    if(size%2 == 1) {
        curr1 = curr1->next;
    }
    
    ListNode* curr2 = list2;
    
    while(curr1 && curr2) {
        if(curr1->val != curr2->val) {
            return 0;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    
    // list1 = reverse(list1);
    // middle->next = list2;
    
    return 1;
}



int main() {
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    // print(head);

    cout<<lPalin(head);

    // print(head);

}
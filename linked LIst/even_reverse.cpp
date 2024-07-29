
#include<iostream>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


void print(ListNode *head) {
    while(head) {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}


ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    
    while(head){
        ListNode* temp = head->next;
        head->next = prev;
        prev = head;
        
        head = temp;
    }
    
    return prev;
} 
 
ListNode* solve(ListNode* A) {
    ListNode* evenList = new ListNode(0);
    ListNode* oddList = new ListNode(0);
    
    ListNode* curr1 = evenList;
    ListNode* curr2 = oddList;
    
    ListNode* curr = A;
    
    bool flag = false;
    
    while(curr) {
        // even
        if(flag) {
            curr1->next = curr;
            curr1 = curr;
            flag = false;
            
        // odd    
        }else {
            curr2->next = curr;
            curr2 = curr;
            flag = true;
        }
        
        curr = curr->next;
    }
    
    curr1->next = nullptr;
    curr2->next = nullptr;
    print(evenList->next);
    evenList->next = reverse(evenList->next);
    
    curr1 = evenList->next;
    curr2 = oddList->next;
    
    
    ListNode* newList = new ListNode(0);
    ListNode* newListCurr = newList;

    print(curr2);
    
    flag = false;
    // marging
    while(curr1 && curr2) {
        if(flag) {
            newListCurr->next = curr1;
            newListCurr = newListCurr->next;
            curr1 = curr1->next;
            flag = false;
            
        // odd    
        }else {
            newListCurr->next = curr2;
            newListCurr = newListCurr->next;
            curr2 = curr2->next;
            flag = true;
        }
    }
    
    if(curr1) {
        newListCurr->next = curr1;
        newListCurr = curr1;
    }
    
    if(curr2){
        newListCurr->next = curr2;
        newListCurr = curr2;
    }
    
    newListCurr->next = nullptr;
    
    return newList->next;
}




int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // print(head);

    head = solve(head);

    print(head);

}
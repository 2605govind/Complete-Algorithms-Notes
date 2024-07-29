#include<iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

 
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


int findSizeOfList(ListNode* head) {
    int count = 0;
    while(head) {
        count++;
        head = head->next;
    }
    return count;
}

ListNode* reverseList(ListNode* A, int B) {
    int size = findSizeOfList(A);
    
    int totalReverse = size / B;
    
    ListNode* curr = A;
    ListNode* dummy = new ListNode(0);
    ListNode* it = dummy;
    
    while(totalReverse) {
        int i = 1;
        ListNode* firstList = curr;
        
        while(curr && i < B) {
            curr = curr->next;
            i++;
        }

        if(curr == nullptr) {
            break;
        }
        
        ListNode* secondList = curr->next;
        curr->next = nullptr;
        
        it->next = reverse(firstList);
        while(it->next) {
            it = it->next;
        }        

        curr = secondList;
        totalReverse--;
    } 
    

    return dummy->next;
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

    head = reverseList(head,2);

    print(head);

}
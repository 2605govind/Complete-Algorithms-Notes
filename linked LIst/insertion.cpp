#include<iostream>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

 
ListNode* reverse(ListNode *head) {
    ListNode *prev = nullptr;
    
    while(head) {
        ListNode *temp = head->next;
        head->next = prev;
        prev = head;
        
        head = temp;
    }
    
    return prev;
}
 
void puttingRightPlace(ListNode* list){
    ListNode* curr = list;
    int key = curr->val;
    
    while(curr->next) {
        if(key < curr->next->val) {
            curr->val = curr->next->val;
        }else{
            break;
        }

        curr = curr->next;
    }    
    
    curr->val = key;
} 

ListNode* insertionSortList(ListNode* A) {
    // if(A == nullptr || A->next == NULL) return A;
    
    ListNode *curr = A->next;
    ListNode *prev = A;
    
    while(curr) {

        if(curr->val < prev->val) {
            swap(curr->val, prev->val);
            
            prev->next = nullptr;

            A = reverse(A);
            
            puttingRightPlace(A);
            
            A = reverse(A);
            
            prev->next = curr;
        }
        
        prev = curr;
        curr = curr->next;
    }
    
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
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);

    print(head);

    head = insertionSortList(head);

    print(head);

}
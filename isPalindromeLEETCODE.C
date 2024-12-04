/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head) {
    if(head==NULL||head->next==NULL){
        return true;
    }
    
   struct ListNode *fast=head;
     struct ListNode *slow=head;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
         struct ListNode *prev=NULL;
       struct ListNode *curr=slow;
        while(curr!=NULL){
            struct ListNode *Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
        }
     struct ListNode *frst=head;
     struct ListNode *sec=prev;
    while(sec!=NULL){
        if(frst->val!=sec->val){
            return false;
        }
        frst=frst->next;
        sec=sec->next;
    }
    return true;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    int count(ListNode* head){
        int count=0;
        ListNode* curr=head;
        while(curr != NULL){
            count++;
            curr=curr->next;
        }
        return count;
    }
    ListNode* findMiddle(ListNode* head){
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast != NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next=NULL;
        while(curr!= NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return;
        }
        int size=count(head);
        ListNode* middle=findMiddle(head);
        ListNode* rev = middle->next;
        middle->next = NULL;
        rev = reverse(rev);
        ListNode* curr=head;
        ListNode* next=NULL;
        // ListNode* rev=reverse(head);
        ListNode* revNext=NULL;
        while(rev !=NULL){
            next=curr->next;
            revNext=rev->next;

            curr->next=rev;
            rev->next=next;
            curr=next;
            rev = revNext;
        }

    }
};
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
private:
    
    ListNode* findMiddle(ListNode* head) {
        int count=0;
        ListNode* temp=head;
        while(temp != NULL){
            temp=temp->next;
            count++;
        }
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL){
            fast=fast->next;
            if(fast->next != NULL){
                fast=fast->next;
            }
            slow=slow->next;
        }
        if(count%2==0){
            return slow->next;
        }
        else{

        return slow;
        }
    }

public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        if (head->next->next == NULL) {
            head->next = NULL;
            return head;
        }
        ListNode* curr=head;
        ListNode* middle=findMiddle(head);
        while(curr != NULL){
            if(curr->next==middle){
                curr->next=curr->next->next;
                break;
            }
            curr=curr->next;
        }
        return head;
    }
};
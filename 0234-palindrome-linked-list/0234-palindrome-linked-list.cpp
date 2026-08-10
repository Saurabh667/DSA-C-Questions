// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// private:
//     ListNode* reverse(ListNode* head){

//         ListNode* prev=NULL;
//         ListNode* curr=head;
//         ListNode* next=NULL;
//         while(curr != NULL){
//             next=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=next;
//         }
//         return prev;
//     }
// public:
//     bool isPalindrome(ListNode* head) {
//         if(head == NULL || head->next == NULL){
//             return true;
//         }
//         ListNode* send=head;
        
//         ListNode* temp=head;
//         ListNode* rev=reverse(copyHead);
//         while(temp != NULL){
//             if(temp->val==rev->val){
//                 temp=temp->next;
//                 rev=rev->next;
//             }
//             else{
//                 return false;
//             }
//         }
//         return true;
//     }
// };


class Solution {
private:
    ListNode* reverse(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while (curr != NULL) {

            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {

        if (head == NULL || head->next == NULL) {
            return true;
        }

        // Create a copy of the linked list
        ListNode* copyHead = new ListNode(head->val);
        ListNode* copyTemp = copyHead;
        ListNode* temp = head->next;

        while (temp != NULL) {

            copyTemp->next = new ListNode(temp->val);
            copyTemp = copyTemp->next;
            temp = temp->next;
        }

        // Reverse the copied list
        ListNode* rev = reverse(copyHead);

        // Reset temp to the original list
        temp = head;

        // Compare original and reversed copy
        while (temp != NULL) {

            if (temp->val != rev->val) {
                return false;
            }

            temp = temp->next;
            rev = rev->next;
        }

        return true;
    }
};
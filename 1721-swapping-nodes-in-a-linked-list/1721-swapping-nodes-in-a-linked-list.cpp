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
    int countFunction(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    };
    void swapNode(ListNode* a, ListNode* b) {
        int temp = a->val;
        a->val = b->val;
        b->val = temp;
    }

public:
    ListNode* swapNodes(ListNode* head, int k) {

        int count = countFunction(head);
        ListNode* temp = head;
        ListNode* start = NULL;
        ListNode* end = NULL;
        int first = k;
        int last = count - k + 1;
        int at = 1;
        while (temp != NULL) {
            if (at == first)
                start = temp;

            if (at == last)
                end = temp;

            temp = temp->next;
            at++;
        };
        // swapNode(start, end);
        if (start != NULL && end != NULL){
            swapNode(start,end);
            }
        return head;
    }
};
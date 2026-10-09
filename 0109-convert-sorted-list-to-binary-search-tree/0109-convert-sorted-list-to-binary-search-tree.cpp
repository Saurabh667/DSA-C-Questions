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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int length(ListNode* head) {
        int size = 0;
        ListNode* temp = head;
        if (temp == NULL) {
            return size;
        }
        while (temp != NULL) {
            size++;
            temp = temp->next;
        }
        return size;
    }
    int pValue(ListNode*& head, int pos) {
        ListNode* temp = head;
        while (pos > 0 && temp != NULL) {
            temp = temp->next;
            pos--;
        }
        if (temp == NULL) {
            return 0;
        }

        return temp->val;
    }
    TreeNode* solve(ListNode*& head, int left, int right) {
        if (left > right) {
            return NULL;
        }
        int mid = left + (right - left) / 2;
        int data = pValue(head, mid);
        TreeNode* root = new TreeNode(data);
        root->left = solve(head, left, mid - 1);
        root->right = solve(head, mid + 1, right);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int size = length(head);
        if (size == 0) {
            return NULL;
        }
        return solve(head, 0, size-1);
    }
};
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
    vector<int> ans;
    vector<int> arr1;
    vector<int> arr2;
    void inorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inorder(root->left);
        arr1.push_back(root->val);
        inorder(root->right);
    }
    void inorder2(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inorder2(root->left);
        arr2.push_back(root->val);
        inorder2(root->right);
    }
    vector<int> mergeArrays(vector<int>& a, vector<int>& b) {


        int i = 0;
        int j = 0;

        while (i < a.size() && j < b.size()) {

            if (a[i] <= b[j]) {
                ans.push_back(a[i]);
                i++;
            } else {
                ans.push_back(b[j]);
                j++;
            }
        }
        while (i < a.size()) {
            ans.push_back(a[i]);
            i++;
        }

        while (j < b.size()) {
            ans.push_back(b[j]);
            j++;
        }

        return ans;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        inorder(root1);
        inorder2(root2);
        return mergeArrays(arr1,arr2);
    }
};
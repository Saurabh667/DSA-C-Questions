/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if(preorder.size()==0 || postorder.size()==0){
            return NULL;
        }
        TreeNode* root= new TreeNode(preorder[0]);
        if(preorder.size() == 1) {
            return root;
        }
        int pos = 0;
        while(postorder[pos] != preorder[1]) {
            pos++;
        }
        vector<int> leftPreOrder(
            preorder.begin() + 1,
            preorder.begin() + pos + 2
        );
        vector<int> leftPostOrder(
            postorder.begin(),
            postorder.begin() + pos + 1
        );
        vector<int> rightPreOrder(
            preorder.begin() + pos + 2,
            preorder.end()
        );

        vector<int> rightPostOrder(
            postorder.begin() + pos + 1,
            postorder.end() - 1
        );

        root->left = constructFromPrePost(leftPreOrder, leftPostOrder);
        root->right = constructFromPrePost(rightPreOrder, rightPostOrder);
        return root;
    }
};
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0 || inorder.size()==0){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        int pos=0;
        while(preorder[0]!=inorder[pos]){
            pos++;
        }
        vector<int> leftPreOrder(preorder.begin()+1,preorder.begin()+1+pos);
        vector<int> leftInOrder(inorder.begin(),inorder.begin()+pos);
        vector<int> rightPreOrder(preorder.begin()+1+pos,preorder.end());
        vector<int> rightInOrder(inorder.begin()+pos+1,inorder.end());
        root->left=buildTree(leftPreOrder,leftInOrder);
        root->right=buildTree(rightPreOrder,rightInOrder);

        return root;
    }
};
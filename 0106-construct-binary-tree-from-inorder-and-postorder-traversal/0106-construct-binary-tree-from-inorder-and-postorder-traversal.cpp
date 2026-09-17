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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size()==0 || inorder.size()==0){
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[postorder.size() - 1]);
        int pos=0;
        while(inorder[pos]!=postorder[postorder.size() - 1]){
            pos++;
        }

        vector<int> LeftPostOrder(postorder.begin(),postorder.begin()+pos);
        vector<int> LeftInOrder(inorder.begin(),inorder.begin()+pos);

        vector<int> RightInOrder(inorder.begin()+pos+1,inorder.end());
        vector<int> RightPostOrder(postorder.begin()+pos,postorder.end()-1);

        root->left=buildTree(LeftInOrder,LeftPostOrder);
        root->right=buildTree(RightInOrder,RightPostOrder);
        return root;
    }
};
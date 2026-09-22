// i have passed 56 test cases out of 60 with this code........
// class Solution {
// public:

//     int maxSum = INT_MIN;
//     bool checkBST(TreeNode* root, long long low, long long high) {

//         if (root == NULL) {
//             return true;
//         }

//         if (root->val <= low || root->val >= high) {
//             return false;
//         }

//         return checkBST(root->left, low, root->val) &&
//                checkBST(root->right, root->val, high);
//     }
//     int sum(TreeNode* root) {
//         if (root == NULL) {
//             return 0;
//         }
//         int total = sum(root->left);
//         total += root->val;
//         total += sum(root->right);
//         return total;
//     }
//     int maxSumBST(TreeNode* root) {
//         if (root == nullptr) return maxSum;
//         if (checkBST(root, LLONG_MIN, LLONG_MAX)) {
//             int value = sum(root);
//             if (value >= maxSum) {
//                 maxSum = value;
//             }
//         }
//             maxSumBST(root->left);
//             maxSumBST(root->right);
        
//         if(maxSum<0){
//             return 0;
//         }
//         return maxSum;
//     }
// };


class Solution {
public:
    int maxSum = 0;

    // returns {isBST, minVal, maxVal, sum}
    array<long long, 4> helper(TreeNode* root) {
        if (!root) return {1, LLONG_MAX, LLONG_MIN, 0};

        auto left = helper(root->left);
        auto right = helper(root->right);

        bool isBST = left[0] && right[0] &&
                     root->val > left[2] && root->val < right[1];

        if (!isBST) return {0, 0, 0, 0};

        long long sum = left[3] + right[3] + root->val;
        maxSum = max(maxSum, (int)sum);

        long long minVal = min((long long)root->val, left[1]);
        long long maxVal = max((long long)root->val, right[2]);
        return {1, minVal, maxVal, sum};
    }

    int maxSumBST(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};
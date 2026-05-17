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
    int rangeSumBST(const TreeNode* root, const int low, const int high) {
        if (root == nullptr) {
            return 0;
        }

        if (root->val >= low && root->val <= high) {
            return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        }

        return rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }

    // int rangeSumBST(TreeNode* root, int low, int high) {
    //     dfs(root, low, high);

    //     return sum;
    // }

    // void dfs(TreeNode* node, int low, int high) {
    //     if (node == nullptr) {
    //         return;
    //     }

    //     if (node->val >= low && node->val <= high) {
    //         sum += node->val;
    //     }

    //     dfs(node->left, low, high);
    //     dfs(node->right, low, high);
    // }

    // int sum{};
};
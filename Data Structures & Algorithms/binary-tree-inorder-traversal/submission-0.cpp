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
    vector<int> inorderTraversal(TreeNode* root) {
        traverse(root);

        return vec;
    }

    void traverse(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        traverse(node->left);
        vec.push_back(node->val);
        traverse(node->right);
    }

    vector<int> vec{};
};
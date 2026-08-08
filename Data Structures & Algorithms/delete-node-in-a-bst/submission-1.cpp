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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;

        if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else {
            if (root->left == nullptr) return root->right;
            if (root->right == nullptr) return root->left;

            auto* current = getMinNode(root->right);
            root->val = current->val;
            root->right = deleteNode(root->right, current->val);
        }

        return root;
    }

    TreeNode* getMinNode(TreeNode* node) {
        auto* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }

        return current;
    }
};
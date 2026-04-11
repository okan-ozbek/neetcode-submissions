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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return iterate(root, 0); 
    }

    int iterate(TreeNode* node, int depth) {
        if (node == nullptr) {
            return depth;
        }

        ++depth;

        int left = iterate(node->left, depth);
        int right = iterate(node->right, depth);

        if (left > right) {
            return left;
        }

        return right;
    }
};

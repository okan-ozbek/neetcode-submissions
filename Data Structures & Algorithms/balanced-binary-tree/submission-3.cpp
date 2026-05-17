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
    bool isBalanced(TreeNode* root) {
        return std::get<0>(dfs(root));
    }

    std::tuple<bool, int> dfs(TreeNode* node) {
        if (node == nullptr) {
            return std::make_tuple(true, 0);
        }

        auto left = dfs(node->left);
        auto right = dfs(node->right);

        bool balanced = std::get<0>(left) && std::get<0>(right) && 
                        std::abs(std::get<1>(left) - std::get<1>(right)) <= 1;

        int height = 1 + std::max(std::get<1>(left), std::get<1>(right));

        return std::make_tuple(balanced, height);
    }
};

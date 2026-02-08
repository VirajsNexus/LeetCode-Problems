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
    bool isBalanced(TreeNode* root) 
    {
        // If the helper returns anything other than -1, it's balanced
        return getHeight(root) != -1;
    }

    private:
    int getHeight(TreeNode* node) 
    {
        // Base case: An empty tree has a height of 0
        if (!node) 
            return 0;

        // 1. Get height of left subtree
        int left = getHeight(node->left);
        if (left == -1) 
            return -1; // Already unbalanced

        // 2. Get height of right subtree
        int right = getHeight(node->right);
        if (right == -1)   
            return -1; // Already unbalanced

        // 3. Check if current node is unbalanced
        // (Difference between heights is more than 1 (absolute value))
        if (abs(left - right) > 1) 
            return -1;

        // 4. Return the actual height if balanced
        return max(left, right) + 1;
    }
};
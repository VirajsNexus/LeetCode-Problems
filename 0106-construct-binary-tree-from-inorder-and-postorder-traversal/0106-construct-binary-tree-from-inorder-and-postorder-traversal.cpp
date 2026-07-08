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
    int postIndex;
    
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int left, int right)
    {
        if (left > right)
            return NULL;

        int rootValue = postorder[postIndex];
        postIndex--;

        TreeNode* root = new TreeNode(rootValue);

        int index = left;
        while (inorder[index] != rootValue)
            index++;

        // right subtree first
        root->right = build(inorder, postorder, index + 1, right);
        root->left = build(inorder, postorder, left, index - 1);

        return root;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        postIndex = postorder.size() - 1;
        return build(inorder, postorder, 0, inorder.size() - 1);    
    }
};
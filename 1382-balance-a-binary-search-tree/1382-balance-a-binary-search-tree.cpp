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
vector<int> list;

    // 1. Convert tree to a sorted list
    void makeList(TreeNode* root) {
        if (!root) return;
        makeList(root->left);
        list.push_back(root->val);
        makeList(root->right);
    }

    // 2. Rebuild tree by always picking the middle element
    TreeNode* buildTree(int start, int end) {
        if (start > end) return nullptr;
        
        int mid = (start + end) / 2;
        TreeNode* node = new TreeNode(list[mid]);
        
        node->left = buildTree(start, mid - 1);
        node->right = buildTree(mid + 1, end);
        
        return node;
    }
        
    TreeNode* balanceBST(TreeNode* root) 
    {
        makeList(root);
        return buildTree(0, list.size() - 1);
    }
};
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
    vector <int> result;
    TreeNode* prev = NULL;
    int count = 0;
    int maxCount = 0;

    vector<int> findMode(TreeNode* root) 
    {
        inorder(root);
        return result;    
    }

    void inorder(TreeNode* node)
    {
        if(!node)
            return;
        
        inorder(node -> left);

        if(prev && prev -> val == node -> val)
            count++;
        else
            count = 1;

        if(count > maxCount)
        {
            maxCount = count;
            result.clear();
            result.push_back(node -> val);
        }
        else if(count == maxCount)
        {
            result.push_back(node -> val);
        }

        prev = node;

        inorder(node -> right);
    }
};
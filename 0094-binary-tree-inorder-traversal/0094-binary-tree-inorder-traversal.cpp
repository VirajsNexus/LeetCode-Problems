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
    vector<int> inorderTraversal(TreeNode* rootNode) 
    {
        vector <int> result;
        inorderTraversal(rootNode, result);
        return result;   
    }

    //inorder function
    void inorderTraversal(TreeNode* rootNode, vector <int>& result)
    {
        if(NULL == rootNode)
        {
            return;
        }

        //Step 1: Visit Left Child
        inorderTraversal(rootNode -> left, result);

        //Step 2: Visit back to root
        result.push_back(rootNode -> val);
        
        //Step 3: Visit right Child
        inorderTraversal(rootNode -> right, result);
    }
};
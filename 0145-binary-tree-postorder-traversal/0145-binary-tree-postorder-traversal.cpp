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
    vector<int> postorderTraversal(TreeNode* rootNode) 
    {
            vector <int> result;        //empty vector to store result
            postorder(rootNode, result);
            return result;
    }

    void postorder(TreeNode* rootNode, vector <int>& result)
    {
        if(NULL == rootNode)
        {
            return;
        }

        //step 1: visit left node
        postorder(rootNode -> left, result);
        
        //step 2: visit right node
        postorder(rootNode -> right, result);

        //step 3: visit root node
        result.push_back(rootNode -> val);
    }
};
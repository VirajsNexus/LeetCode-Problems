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
    vector<int> preorderTraversal(TreeNode* rootNode) 
    {
        vector <int> result;    //empty vector
        preorder(rootNode, result);
        return result;
    }

    //Preorder function (to be used recursively)
    void preorder(TreeNode* rootNode, vector<int>& result)
    {
        if(NULL == rootNode)
        {
            return;     //if the root does not exist, there is no tree to traverse
        }

        //Step 1: Visit the root and push the current node's value into the vector
        result.push_back(rootNode -> val);

        //Step 2: visit left child
        preorder(rootNode -> left, result);

        //Step 3: Visit right child
        preorder(rootNode -> right, result);
    }
};
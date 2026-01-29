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
    int countNodes(TreeNode* root) 
    {
        if(NULL == root)
        {
            return 0;
        }    

        int count =0;
        stack<TreeNode*> visitingNode;
        visitingNode.push(root);

        while(!visitingNode.empty())
        {
            TreeNode* node = visitingNode.top();
            visitingNode.pop();
            count++;

            if(node -> left)
            {
                visitingNode.push(node -> left);
            }
            if(node -> right)
            {
                visitingNode.push(node -> right);
            }
        }
        return count;
    }
};
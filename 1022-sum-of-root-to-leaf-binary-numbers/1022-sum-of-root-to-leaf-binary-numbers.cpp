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
    int sumRootToLeaf(TreeNode* root, int current =0) 
    {
        if(NULL == root)
        {
            return 0;
        }    

        //Update current binary number
        current = current * 2 + root -> val;

        if(NULL == root -> left && NULL == root -> right)
        {
            return current;
        }

        //return sum of left and right subtree
        return sumRootToLeaf(root -> left, current)+
               sumRootToLeaf(root -> right, current);

    }
};
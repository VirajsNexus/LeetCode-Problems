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
    TreeNode* searchBST(TreeNode* root, int val) 
    {
           if(NULL == root)
           {
                return NULL;                            // tree is empty
           }

            if(root -> val == val)                      //value found at root
            {
                return root;
            }

            if(val < root -> val)                       //Search in left sub-tree
            {
                return searchBST(root -> left, val);
            }

            else                                        //Search in right sub-tree
            {
                return searchBST(root -> right, val);
            }
    }
};
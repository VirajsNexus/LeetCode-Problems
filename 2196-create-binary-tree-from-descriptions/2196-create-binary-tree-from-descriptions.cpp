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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions)
    {
        int maxVal = 0;

        for(int i = 0; i < descriptions.size(); i++)
        {
            maxVal = max(maxVal, descriptions[i][0]);
            maxVal = max(maxVal, descriptions[i][1]);
        }

        vector<TreeNode*> nodes(maxVal + 1, NULL);
        vector<bool> isChild(maxVal + 1, false);

        for(int i = 0; i < descriptions.size(); i++)
        {
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            int isLeft = descriptions[i][2];

            if(nodes[parent] == NULL)
                nodes[parent] = new TreeNode(parent);

            if(nodes[child] == NULL)
                nodes[child] = new TreeNode(child);

            if(isLeft == 1)
                nodes[parent]->left = nodes[child];
            else
                nodes[parent]->right = nodes[child];

            isChild[child] = true;
        }

        for(int i = 0; i < descriptions.size(); i++)
        {
            int parent = descriptions[i][0];

            if(isChild[parent] == false)
                return nodes[parent];
        }

        return NULL;
    }
};
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) 
    {
        int size1 = boxGrid.size();
        int size2 = boxGrid[0].size();

        //Step 1: gravity
        for(int i = 0; i < size1; i++)
        {
            int empty = size2 -1;                // rightmost empty position

            for(int j = size2 - 1;  j >= 0; j--)
            {
                if(boxGrid[i][j] == '*')
                {
                    empty = j -1;       //stone fall before obstacle
                }
                else if(boxGrid[i][j] == '#')
                {
                    swap(boxGrid[i][j], boxGrid[i][empty]);
                    empty--;
                }
            }
        }  

        //step 2:  rotate 
        vector<vector<char>> ans(size2, vector<char>(size1));

        for(int i =0; i < size1; i++)
        {
            for(int j = 0; j < size2; j++)
            {
                ans[j][size1 -1 -i] = boxGrid[i][j];
            }
        }
        return ans;
    }
};
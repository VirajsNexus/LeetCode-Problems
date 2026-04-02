class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> pascalsTriangle;

        for(int i = 0; i < numRows; i++)
        {
            vector<int> row(i + 1, 1); // initialize with 1s

            for(int j = 1; j < i; j++)
            {
                row[j] = pascalsTriangle[i - 1][j - 1] + pascalsTriangle[i - 1][j];
            }

            pascalsTriangle.push_back(row);
        }

        return pascalsTriangle;
    
    }
};
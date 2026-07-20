class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) 
    {
        int rows = grid.size();
        int columns = grid[0].size();

        int total = rows * columns;

        k = k % total;

        vector<vector<int>> result(rows, vector<int>(columns));

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                int currentIndex = i * columns + j;

                int newIndex = (currentIndex + k) % total;

                int newRow = newIndex / columns;
                int newColumns = newIndex % columns;

                result[newRow][newColumns] = grid[i][j];
            }
        }   
        return result;
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {

        //Logic same as a binary search just rows and columns are come in picture
        //calculating rows and columns of a matrix
        int rows = matrix.size();
        int columns = matrix[0].size(); 

        //Use binary search
        int left = 0;
        int right = rows * columns -1;
        int FirstTrueIndex = -1;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            
            //convert coordinates from 1D to 2D
            int Row2D = mid / columns;
            int Column2D = mid % columns;

            //condition : matrix[rows][columns] >= target;
            if(matrix[Row2D][Column2D] >= target)
            {
                FirstTrueIndex = mid;
                right = mid -1;
            }
            else
            {
                left = mid +1;
            }
        }
        //Checking for FirstTrueIndex is pointing to the target or not
        if(FirstTrueIndex == -1)
        {
            return false;
        }

        int targetRow = FirstTrueIndex / columns;
        int targetColumn = FirstTrueIndex % columns;

        return matrix[targetRow][targetColumn] == target;
    }
};
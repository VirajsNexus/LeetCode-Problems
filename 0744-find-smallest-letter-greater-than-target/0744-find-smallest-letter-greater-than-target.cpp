class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        //Logic : Use 
        int n = letters.size();
        int left = 0;
        int right = n - 1;
        int firstTrueIndex = -1;

        //Binary search to find the first index where letters[mid] > target
        while (left <= right) 
        {
            int mid = left + (right - left) / 2;

            //is this character greater than target
            if (letters[mid] > target) 
            {
                firstTrueIndex = mid;  //Can be a result
                right = mid - 1;  // Search left for smaller valid index
            } 
            else 
            {
                left = mid + 1;  // Search right
            }
        }

        //if no character is greater, return first character
        if (firstTrueIndex == -1) 
        {
            return letters[0];
        }

        return letters[firstTrueIndex];
    }
};
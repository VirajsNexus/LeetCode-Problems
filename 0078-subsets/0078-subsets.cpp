class Solution {
public:

    void backtrack(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result)
    {
        // Add the current subset to the result
        result.push_back(current);

        for(int i = index; i < nums.size(); i++)
        {   
            // Choose the current element
            current.push_back(nums[i]);  

            // Explore further with the next index
            backtrack(nums, i + 1, current, result);

            // backtracking (UNDO)
            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> result;
        vector<int> current;

        // Started backtracking from 0th index
        backtrack(nums, 0, current, result);

        return result;   
    }
};
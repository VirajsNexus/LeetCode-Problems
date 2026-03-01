class Solution {
public:
    vector<int> runningSum(vector<int>& nums) 
    {
        // Iterate through the array starting from the second element
        for(int i = 1; i < nums.size(); ++i)
        {
            //Add the previous element to the current element
            nums[i] = nums[i - 1];
        }    

        return nums;
    }
};
class Solution {
public:
    int absDifference(vector<int>& nums, int k) 
    {
        //sort array
        sort(nums.begin(), nums.end());

        int size = nums.size();
        int smallSum = 0;
        int largeSum = 0;

        //sum of k smallest elements
        for(int i = 0; i < k; i++)
        {
            smallSum += nums[i];
        }    

        //sum of k largest elements
        for(int i = 0; i < k; i++)
        {
            largeSum += nums[size - 1 - i];
        }

        //Return absolute difference
        return abs(largeSum - smallSum);
    }
};
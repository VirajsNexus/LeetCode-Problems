class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) 
    {
        int maxElement = nums[0];
        int minElement = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > maxElement)
                maxElement = nums[i];
            
            if(nums[i] < minElement)
                minElement = nums[i];
        }

        long long result = (long long)(maxElement - minElement) * k;
        return result;
    }
};
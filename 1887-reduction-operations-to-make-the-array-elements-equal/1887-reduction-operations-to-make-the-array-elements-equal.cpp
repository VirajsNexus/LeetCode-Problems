class Solution {
public:
    int reductionOperations(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());

        int size = nums.size();
        int result = 0;

        for(int i = 1; i < size; i++)
        {
            if(nums[i] != nums[i - 1])
            {
                result += size - i;
            }
        }    
        return result;
    }
};
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) 
    {
        int size = nums.size();
        int result = 0;

        for(int i = 0; i < size; i++)
        {
            int targetCount = 0;

            for(int j = i; j < size; j++)
            {
                if(nums[j] == target)
                {
                    targetCount++;
                }
                int length = j - i + 1;

                if(targetCount > length / 2)
                {
                    result++;
                }
            }
        }    
        return result;
    }
};
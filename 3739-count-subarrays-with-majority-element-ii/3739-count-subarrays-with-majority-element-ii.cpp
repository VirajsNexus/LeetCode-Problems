class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) 
    {
            int size = nums.size();
            vector<int> prefix(size * 2 + 1, 0);
            prefix[size] = 1;
            int count = size;
            long long result = 0;
            long long prefixsum = 0;

            for(int i = 0; i < size; ++i)
            {
                if(nums[i] == target)
                {
                    prefixsum += prefix[count];
                    ++count;
                    ++prefix[count];
                }
                else
                {
                    --count;
                    prefixsum -= prefix[count];
                    ++prefix[count];
                }
                result += prefixsum;
            }
            return result;
    }
};
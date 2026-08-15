class Solution {
public:
    int longestSubsequence(vector<int>& nums) 
    {
        int size = nums.size();
        int xOr = 0;
        bool nonZero = false;

        for(int i = 0; i < size; i++)
        {
            xOr ^= nums[i];

            if(nums[i] != 0)
            {
                nonZero = true;
            }
        }    
        if(xOr != 0)
        {
            return size;
        }

        if(nonZero)
        {
            return size - 1;
        }

        return 0;
    }
};
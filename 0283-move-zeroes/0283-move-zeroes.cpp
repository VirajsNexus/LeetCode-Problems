class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int position = 0;
        int size = nums.size();

        for(int current = 0; current < size; ++current)
        {
            if(nums[current] != 0)
            {
                swap(nums[current], nums[position]);
                position++;
            }
        }    
    }
};
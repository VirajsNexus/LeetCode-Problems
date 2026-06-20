class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int size = nums.size();

        //place each number x at index x-1
        for(int i = 0; i < size; i++)
        {
            while(nums[i] >= 1 && nums[i] <= size && nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }


        //finding first index where nums[i] != i + 1
        for(int i = 0; i < size; i++)
        {
            if(nums[i] != i + 1)
                return i + 1;
        }

        //if all positions are correct
        return size + 1;
    }
};
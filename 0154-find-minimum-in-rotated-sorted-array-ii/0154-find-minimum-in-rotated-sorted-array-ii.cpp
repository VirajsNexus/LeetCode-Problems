class Solution 
{
public:
    int findMin(vector<int>& nums) 
    {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) 
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] < nums[high]) 
            {
                // Minimum is in left half including mid
                high = mid;
            }
            else if (nums[mid] > nums[high]) 
            {
                // Minimum is in right half excluding mid
                low = mid + 1;
            }
            else 
            {
                // nums[mid] == nums[high]
                // Cannot decide the side, reduce high by 1
                high--;
            }
        }

        return nums[low];
    }
};
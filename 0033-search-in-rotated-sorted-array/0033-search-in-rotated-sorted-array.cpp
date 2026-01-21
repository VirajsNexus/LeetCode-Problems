class Solution {
public:
    int search(vector<int>& nums, int target) 
    {

        //hint : use logic like binary search
        int start = 0;
        int end = nums.size() -1;

        while(start <= end)
        {
            int mid = start + (end - start) / 2;

            //Case 1 : if target is on mid
            if(nums[mid] == target)
            {
                return mid;
            }
            //case 2 : target is either on left or right side  

            // Check which part is sorted 
            //Left part
            if(nums[start] <= nums[mid])
            {
                //check for target 
                if(nums[start] <= target && target < nums[mid])
                {
                    end = mid -1;   //target is on left side
                }
                else
                {
                    start = mid +1; //target is on right side
                }
            }
            //right part
            else
            {   
                if(nums[mid] < target && target <= nums[end])
                {
                    start = mid +1;     //target on right side
                }
                else
                {
                    end = mid -1;       //target is on left side
                }
            }
        }
        return -1;      //target not found
    }
};
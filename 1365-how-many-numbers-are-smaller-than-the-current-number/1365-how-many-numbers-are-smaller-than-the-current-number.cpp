class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        //Hint: sort array and use binary search

         // Step 1: Copy and sort the array
        vector<int> sortedArray = nums;  //array copied
        sort(sortedArray.begin(), sortedArray.end());

        // Step 2: Apply binary search for each element
        for (int i = 0; i < nums.size(); i++) 
        {

            int target = nums[i];
            int left = 0;
            int right = sortedArray.size() - 1;
            int end = sortedArray.size();

            // Binary search to find first index where sorted[index] >= target
            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (sortedArray[mid] >= target) 
                {
                    end = mid;
                    right = mid - 1;     // search left part
                } 
                else 
                {
                    left = mid + 1;      // search right part
                }
            }

            // position is the count of smaller elements
            nums[i] = end;
        }

        return nums;
    }
};
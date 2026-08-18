class Solution {
public:
    int largestInteger(vector<int>& nums, int k) 
    {
        int size = nums.size();

        // Start from largest number
        for (int x = 50; x >= 0; x--) 
        {
            int cnt = 0;

            // Check every subarray of size k
            for (int i = 0; i <= size - k; i++) 
            {
                bool found = false;

                // Check if x is present in this subarray
                for (int j = i; j < i + k; j++) 
                {
                    if (nums[j] == x) 
                    {
                        found = true;
                        break;
                    }
                }

                // x is present in this subarray
                if (found) 
                {
                    cnt++;
                }
            }

            // x appears in exactly one subarray
            if (cnt == 1) 
            {
                return x;
            }
        }
        return -1;
    }
};
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int left = 0;
        int max_len = 0;
        
        // right pointer expands the window
        for (int right = 0; right < n; ++right) {
            // While the window is not balanced, shrink from the left
            // Use long long for the product to prevent potential overflow
            while (nums[right] > (long long)nums[left] * k) 
            {
                left++;
            }
            
            // The current window [left, right] is balanced
            max_len = max(max_len, right - left + 1);
        }
        
        // Total elements - maximum balanced window = minimum removals
        return n - max_len;
    }
};
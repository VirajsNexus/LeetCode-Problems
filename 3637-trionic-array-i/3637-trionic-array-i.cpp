class Solution {
public:
    bool isTrionic(vector<int>& nums) 
    {
        int n = nums.size();
        if (n < 3) return false; // Basic size check

        int i = 0;

        // 1. Walk UP the first hill
        while (i < n - 1 && nums[i] < nums[i + 1]) 
        {
            i++;
        }

        // Check: Did we get stuck at start or go strictly up to the end?
        if (i == 0 || i == n - 1) 
        {
            return false;
        }

        // 2. Walk DOWN into the valley
        int peakIndex = i;
        while (i < n - 1 && nums[i] > nums[i + 1]) 
        {
            i++;
        }

        // Check: Did we not move down? OR did we reach the end while moving down?
        // (We need space left for the final UP)
        if (i == peakIndex || i == n - 1) 
        {
            return false;
        }

        // 3. Walk UP the final hill
        while (i < n - 1 && nums[i] < nums[i + 1]) 
        {
            i++;
        }

        // Final Check: Did we make it to the end?
        return i == n - 1;
    }
};
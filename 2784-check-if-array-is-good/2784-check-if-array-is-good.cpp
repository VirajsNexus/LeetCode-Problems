class Solution {
public:
    bool isGood(vector<int>& nums) 
    {
        int n = *max_element(nums.begin(), nums.end());

        // Size must be exactly n + 1
        if (nums.size() != n + 1)
            return false;

        // Count frequency of each number
        vector<int> freq(n + 1, 0);

        for (int x : nums) 
        {
            // Number must be between 1 and n
            if (x < 1 || x > n)
                return false;
            freq[x]++;
        }

        // Numbers 1 to n-1 must appear exactly once
        for (int i = 1; i < n; i++) 
        {
            if (freq[i] != 1)
                return false;
        }

        // Number n must appear exactly twice
        if (freq[n] != 2)
            return false;

        return true;
    }
};
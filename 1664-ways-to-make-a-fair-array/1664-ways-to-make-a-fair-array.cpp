class Solution {
public:
    int waysToMakeFair(vector<int>& nums) 
    {
        int evenSum = 0, oddSum = 0;

        // Total sums of even and odd indices
        for (int i = 0; i < nums.size(); i++) 
        {
            if (i % 2 == 0) evenSum += nums[i];
            else oddSum += nums[i];
        }

        int leftEven = 0, leftOdd = 0, ans = 0;

        for (int i = 0; i < nums.size(); i++) 
        {
            // Remove current element from right side
            if (i % 2 == 0) evenSum -= nums[i];
            else oddSum -= nums[i];

            // After removal, right side indices change parity
            if (leftEven + oddSum == leftOdd + evenSum)
                ans++;

            // Add current element to left side
            if (i % 2 == 0) leftEven += nums[i];
            else leftOdd += nums[i];
        }

        return ans;
    }
};
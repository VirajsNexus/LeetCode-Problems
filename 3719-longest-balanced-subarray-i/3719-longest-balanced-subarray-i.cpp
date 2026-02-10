class Solution {
public:
    int longestBalanced(vector<int>& nums) 
    {
        int n = nums.size();
        int maxLen = 0;

        // Check every possible subarray starting at i and ending at j
        for (int i = 0; i < n; ++i) {
            unordered_set<int> distinctEvens;
            unordered_set<int> distinctOdds;

            for (int j = i; j < n; ++j) {
                // Insert number into the corresponding set
                // Sets automatically handle duplicates, so we don't need to check manually
                if (nums[j] % 2 == 0) {
                    distinctEvens.insert(nums[j]);
                } else {
                    distinctOdds.insert(nums[j]);
                }

                // If the count of distinct evens matches distinct odds, update max length
                if (distinctEvens.size() == distinctOdds.size()) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};
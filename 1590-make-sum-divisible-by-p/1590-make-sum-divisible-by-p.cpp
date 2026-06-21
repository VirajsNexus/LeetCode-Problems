class Solution {
public:
    int minSubarray(vector<int>& nums, int p) 
    {
        long long totalSum = 0;

        for (int num : nums)
            totalSum += num;

        int rem = totalSum % p;

        if (rem == 0)
            return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;

        long long prefixSum = 0;
        int ans = nums.size();

        for (int i = 0; i < nums.size(); i++) 
        {
            prefixSum += nums[i];

            int curr = prefixSum % p;
            int target = (curr - rem + p) % p;

            if (mp.count(target))
                ans = min(ans, i - mp[target]);

            mp[curr] = i;
        }

        return (ans == nums.size()) ? -1 : ans;
    }
};
class Solution
{
public:
    vector<long long> distance(vector<int>& nums)
    {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;
        vector<long long> ans(n, 0);

        // Step 1: store indices of each number
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]].push_back(i);
        }

        // Step 2: process each group
        for (auto it : mp)
        {
            vector<int> pos = it.second;
            int k = pos.size();

            if (k == 1)
            {
                continue;
            }

            // Step 3: prefix sum of indices
            vector<long long> prefix(k, 0);

            prefix[0] = pos[0];

            for (int i = 1; i < k; i++)
            {
                prefix[i] = prefix[i - 1] + pos[i];
            }

            long long totalSum = prefix[k - 1];

            // Step 4: compute answer for each index in group
            for (int i = 0; i < k; i++)
            {
                long long leftSum = 0;
                long long rightSum = 0;

                // left side contribution
                if (i > 0)
                {
                    leftSum = (long long)i * pos[i] - prefix[i - 1];
                }

                // right side contribution
                if (i < k - 1)
                {
                    rightSum = (totalSum - prefix[i]) - (long long)(k - i - 1) * pos[i];
                }

                ans[pos[i]] = leftSum + rightSum;
            }
        }

        return ans;
    }
};
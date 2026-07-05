class Solution {
public:
    const int MOD = 1000000007;

    int divisibleGame(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());

        unordered_set<int> st;

        for (int x : nums) {
            for (int d = 2; d * d <= x; d++) {
                if (x % d == 0) {
                    st.insert(d);
                    st.insert(x / d);
                }
            }
            if (x > 1)
                st.insert(x);
        }

        st.insert(mx + 1);

        long long bestDiff = LLONG_MIN;
        int bestK = INT_MAX;

        for (int k : st) {
            long long cur = LLONG_MIN;
            long long sum = 0;

            for (int x : nums) {
                long long val = (x % k == 0 ? x : -x);

                if (sum < 0)
                    sum = val;
                else
                    sum += val;

                cur = max(cur, sum);
            }

            if (cur > bestDiff) {
                bestDiff = cur;
                bestK = k;
            } else if (cur == bestDiff && k < bestK) {
                bestK = k;
            }
        }

        long long ans = (bestDiff % MOD + MOD) % MOD;
        ans = (ans * bestK) % MOD;

        return (int)ans;
    }
};
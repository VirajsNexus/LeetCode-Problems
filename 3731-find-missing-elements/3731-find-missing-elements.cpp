class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) 
    {
        int mini = nums[0];
        int maxi = nums[0];

        unordered_set<int> st;

        for (int x : nums) 
        {
            mini = min(mini, x);
            maxi = max(maxi, x);
            st.insert(x);
        }

        vector<int> ans;

        for (int i = mini; i <= maxi; i++) 
        {
            if (st.find(i) == st.end()) 
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
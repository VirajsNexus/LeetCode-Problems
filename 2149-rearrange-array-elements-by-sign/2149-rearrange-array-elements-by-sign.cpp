class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        vector<int> ans(nums.size());
        
        int posIndex = 0; // even index
        int negIndex = 1; // odd index
        
        for(int x : nums)
        {
            if(x > 0)
            {
                ans[posIndex] = x;
                posIndex += 2;
            }
            else
            {
                ans[negIndex] = x;
                negIndex += 2;
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) 
    {
        int ans = INT_MAX;  //largest possible integer value(used for finding minimum and as worst case,beacause I havent found any answer yet thats why not 0)

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == target)
            {
                ans = min(ans, abs(i - start)); //used abs to remove negative sign if any
            }
        }

        return ans;    
    }
};
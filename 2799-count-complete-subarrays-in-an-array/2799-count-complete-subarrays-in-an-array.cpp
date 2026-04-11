class Solution 
{
public:
    int countCompleteSubarrays(vector<int>& nums) 
    {
        int n = nums.size();       
        
        // Step 1: count total distinct elements
        unordered_set<int> st(nums.begin(), nums.end());
        int totalDistinct = st.size();
        
        unordered_map<int,int> freq;
        int left = 0, count = 0;
        
        for(int right = 0; right < n; right++)
        {
            freq[nums[right]]++;
            
            // When window becomes complete
            while(freq.size() == totalDistinct)
            {
                count += (n - right); // all subarrays from right to end
                
                // shrink window
                freq[nums[left]]--;
                if(freq[nums[left]] == 0)
                    freq.erase(nums[left]);
                
                left++;
            }
        }
        
        return count;
    }
};
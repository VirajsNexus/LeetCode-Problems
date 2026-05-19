class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) 
    {
        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size()) 
        {
            if (nums1[i] == nums2[j]) 
            {
                return nums1[i];   // Smallest common element found
            }
            else if (nums1[i] < nums2[j]) 
            {
                i++;               // Move ahead in nums1
            }
            else 
            {
                j++;               // Move ahead in nums2
            }
        }

        return -1; // No common element
    }
};
class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        // Find length of array
        int length = nums.size();

        //Handling K
        // Total rotations without optimization = length of linked list + k
         // Here we can see that we can get our expected output just doing k rotations, no need of length of linked list while for rotations
         k = k % length     // returns optimized count or index

         // Step 1 - reverse entire array
         reverse(nums.begin(), nums.end());

        // step 2 - reverse first k elements
        reverse(nums.begin(), nums.begin() + k );

        // step 3 - reverse remaining n-k elements
        reverse(nums.begin() + k, nums.end());

        //
    }
};
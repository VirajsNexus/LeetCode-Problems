class Solution {
public:
    int maximumProduct(vector<int>& nums) 
    {
        //sort array in assending order
        sort(nums.begin(), nums.end());

        int size = nums.size();

        //Here, there are two possibilities of getting maximum product of three numbers in an array, as we sorted array so the product of 2 negative numbers and largest number is positive and second scenario of product of largest 3 numbers
        return max(
            //product of 3 largest number
            nums[size - 1] * nums[size - 2] * nums[size - 3],

            //product of 2 smallest(negative) and 1 largest number
            nums[0] * nums[1] * nums[size - 1]
        );
    }
};
class Solution {
    public int[] rearrangeArray(int[] nums) 
    {
        int[] arr = new int[nums.length];    

        int oddIndex = 1;
        int evenIndex = 0;

        for(int i = 0; i < nums.length; i++)
        {
            if(nums[i] > 0)
            {
                arr[evenIndex] = nums[i];
                evenIndex = evenIndex + 2;
            }
            else
            {
                arr[oddIndex] = nums[i];
                oddIndex = oddIndex + 2;
            }
        }
        return arr;
    }
}
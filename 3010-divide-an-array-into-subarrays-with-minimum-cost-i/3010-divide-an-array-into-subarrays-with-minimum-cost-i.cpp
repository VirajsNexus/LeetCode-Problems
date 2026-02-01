class Solution {
public:
    int minimumCost(vector<int>& nums) 
    {
        int sum = nums[0];
         
         int smallest = 100;                //Smallest number
         int SecondSmallest = 100;         //Second Smallest number

        //Checking all numbers except first
         for(int i =1; i< nums.size(); i++)
         {
            //if current number smaller than smallest
            if(nums[i] < smallest)
            {
                SecondSmallest = smallest;
                smallest = nums[i];
            }
            //Number is not smallest but smaller than second smallest
            else if(nums[i] < SecondSmallest)
                SecondSmallest = nums[i];
         }
        sum = sum + smallest + SecondSmallest;      //Adding all three  smallest, secondSmallest and  FirstNumber
        return sum;
    }
};
class Solution {
public:
    int differenceOfSums(int n, int m) 
    {
        // num1 will store sum of numbers NOT divisible by m
        // num2 will store sum of numbers divisible by m
        int num1 = 0;
        int num2 = 0;
        
        // Loop from 1 to n
        for(int i = 1; i <= n; i++)
        {
            // Check if current number is divisible by m
            if(i % m == 0) 
                num2 += i;   // Add to divisible sum
            else 
                num1 += i;   // Add to non-divisible sum
        }
        
        // Return the required difference
        return num1 - num2;
    }
};
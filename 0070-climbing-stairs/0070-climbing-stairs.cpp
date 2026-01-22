class Solution {
public:
    int climbStairs(int n) 
    {
        //Hint : Use Fibonacci numbers
        //initialize two variables to track previous two numbers
        //prev1 -> F(i-1)
        //prev2 -> F(i-2)
        int prev1 = 1;
        int prev2 = 0;

        //Calculating nth Fibonacci number iteratively
        //number of ways to climb the n stairs are (n+1)th fibonacci number
        for(int i=0; i< n; ++i)
        {
            //Determine previous fibonacci number F(i) = F(i-1) + F(i-2)
            int current = prev2 + prev1;

            //Move forward by one position
            prev2 = prev1;      //F(i-2) -> F(i-1)
            prev1 = current;    //F(i-1) -> F(i)
        }

        //Return result number of ways are found and represented by 'prev1'
        return prev1;
    }
};
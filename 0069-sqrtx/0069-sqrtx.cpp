class Solution {
public:
    int mySqrt(int x) 
    {
        //Hint : solve like binary search
        //initialize two variables start and end; end will be one more than x
        long long start = 0;
        long long end = (long long)x + 1;

        //Searching until range becomes empty
        while(start < end)
        {
            //finding middle to divide in halves
            long long mid = (start + end)/2;

            //if mid squared is greater than x then the square root must be smaller
            if(mid * mid > x) 
            {
                end = mid;
            }

            // if not then square root definetly present is second halve
            else start = mid + 1;
        }
        //start is now one step ahead of the answer
        return start - 1;    
    }
};
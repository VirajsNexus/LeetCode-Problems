class Solution {
public:
    bool judgeSquareSum(int c) 
    {
           long long limit = sqrt(c);

           for(long long a = 0; a <= limit; a++)
           {
                long long target = c - a * a;
                
                long long low = 0;
                long long high = limit;

                while(low <= high)
                {
                    long long mid = low + (high - low) / 2;
                    long long square = mid * mid;

                    if(square == target)
                    {
                        return true;
                    }
                    else if(square < target)
                    {
                        low  = mid + 1;
                    }
                    else
                    {
                        high = mid - 1;
                    }
                }
           }
           return false;
    }
};
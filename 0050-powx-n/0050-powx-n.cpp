class Solution {
public:
    double myPow(double x, int n) 
    {
        // Three possibilities of n  : 1. negative, 2. even, 3. odd
        // 1. negative :- 1/x^n
        // 2. even :- (x^(n / 2)) * (x^(n / 2))
        // 3. odd :- x * x^n

        //int N = n;                //can't use beacuse of overflow
        long long N = n;             // Used to remove overflow

        if(N < 0)                   // neagative 'n'
        {
            x = 1 /x;
            N = -N;
        }

        double result = 1;
        while(N > 0)        
        {
            if(N % 2 == 1)          // odd 'n'
            {
                result *= x;
            }

            x *= x;                 //positive
            N = N /2;
        }

        return result;
    }
};
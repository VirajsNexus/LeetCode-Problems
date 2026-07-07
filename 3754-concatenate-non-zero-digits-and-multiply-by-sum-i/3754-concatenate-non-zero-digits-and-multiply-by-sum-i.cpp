class Solution {
public:
    long long sumAndMultiply(int n) 
    {
        long long a = 0;
        int tens = 1;
        int addition  = 0;

        while(n > 0)
        {
            int digit = n % 10;
            
            if(digit != 0)
            {
                a += tens * digit;
                tens *= 10;
                addition += digit;
            }
            n /= 10;
        }
        return addition * a;          
    }
};
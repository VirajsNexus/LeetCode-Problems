class Solution 
{
public:
    int smallestEvenMultiple(int n) 
    {
        if(n % 2 == 0)
        {
            return n;       //already divisible by 2
        }           
        else
        {
            return (2 * n);   //making it divisible by 2
        }
    }
};
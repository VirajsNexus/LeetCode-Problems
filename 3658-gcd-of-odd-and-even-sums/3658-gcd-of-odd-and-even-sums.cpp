class Solution {
public:

    int gcd(int a, int b)
    {
        while(b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    int gcdOfOddEvenSums(int n) 
    {   
        int count = 0;
        int sumOdd = 0;
        int sumEven = 0;

        for(int i = 1; count < n; i++)
        {
            if(i % 2 != 0)
            {
                sumOdd += i;
                count++;
            }
        }
        count = 0;
        for(int i = 1; count < n; i++)
        {
            if(i % 2 == 0)
            {
                sumEven += i;
                count ++;
            }
        }

        return gcd(sumOdd, sumEven);
    }
};
class Solution {
public:
    bool checkDivisibility(int n) 
    {
        int originalNum = n;
        int sum = 0;
        int product = 1;
        int total;
        while(n > 0)
        {
            int digit = n % 10;
            sum += digit;
            product *= digit;

            n = n / 10;
        }
        total = sum + product;

        return originalNum % total == 0;
    }
};
class Solution {
public:
    int rotatedDigits(int n) 
    {
        int count = 0;

        for(int i = 1; i <= n; i++)
        {
            if(isGoodNumber(i))
            {
                count++;
            }
        }
        return count;
    }

    bool isGoodNumber(int num)
    {
        bool change = false;

        while(num > 0)
        {
            int digit = num % 10;

            //invalid digits
            if(digit == 3 || digit ==  4 || digit == 7)
            {
                return false;
            }

            // digit can rotate
            if(digit == 2 || digit == 5 || digit == 6 || digit == 9)
            {
                change = true;
            }

            num /= 10;
        }
        return change;

    }
};
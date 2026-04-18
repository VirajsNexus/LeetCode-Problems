class Solution {
public:
    int reverse(int n)
    {
        int result = 0;                     //variable to store result

        while(n)    
        {
            int x = n % 10;                 //last digit extracted     
            n = n / 10;                     //removed last digit
            result = result * 10 + x;       //adds x at last
        }
        return result;
    }

    int mirrorDistance(int n) 
    {
        int reverseN = reverse(n);          //stored reversed n

        int answer = abs( n - reverseN);    //absolute to remove negative sign if any

        return answer;
    }
};
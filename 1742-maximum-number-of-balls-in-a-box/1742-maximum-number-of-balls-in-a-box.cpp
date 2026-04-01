class Solution {
public:
    int countBalls(int lowLimit, int highLimit) 
    {
        vector<int> box(50, 0);
        int answer = 0;

        for(int i = lowLimit; i <= highLimit; i++)
        {
            int sum = 0;
            int n = i;

            while(n > 0)
            {
                sum += n % 10;
                n /= 10;
            }

            box[sum]++;
            answer = max(answer, box[sum]);
        }    
        return answer;
    }
};
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) 
    {
        int size = nums.size();

        long long sum = 0;
        long long fun = 0;

        //sum + f(0)
        for(int i = 0; i < size; i++)
        {
            sum += nums[i];
            fun += (long long)i * nums[i];
        }

        long long answer = fun;

       //next rotations
       for(int k = 1; k < size; k++)
       {
            fun = fun + sum - (long long)size * nums[size - k];
            answer = max(answer, fun);
       }  

    return answer;      
    }
};
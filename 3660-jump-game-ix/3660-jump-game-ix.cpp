class Solution {
public:
    vector<int> maxValue(vector<int>& nums) 
    {
        int size = nums.size();

        vector<int> pre(size);
        vector<int> post(size);

        //maximum prefix
        pre[0] = nums[0];

        for(int i = 1; i < size; i++)
        {
            pre[i] = max(pre[i - 1], nums[i]);
        }    

        //suffix mimimum
        post[size - 1] = nums[size - 1];
        for(int i = size -2; i >= 0; i--)
        {
            post[i] = min(post[i + 1], nums[i]);
        }

        vector <int> answer(size);

        int start = 0;

        for(int i = 0; i < size; i++)
        {
            //group end
            if(i == size - 1 || pre[i] <= post[i + 1])
            {
                int maximum = pre[i];
                for(int j = start; j <= i; j++)
                {
                    answer[j] = maximum;
                }
                start = i + 1;
            }
        }
        return answer;
    }
};
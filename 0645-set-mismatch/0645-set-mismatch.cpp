class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        int size = nums.size();

        int i = 0;
        while(i < size)
        {
            int correctIndex = nums[i] - 1;

            if(nums[i] != nums[correctIndex])
            {
                swap(nums[i], nums[correctIndex]);
            }
            else
            {
                i++;
            }
        }    

        vector <int> answer(2);
        
        for(int i = 0; i < size; i++)
        {
            if(nums[i] != i + 1)
            {
                answer[0] = nums[i];
                answer[1] = i + 1;
            }
        }

        return answer;
    }
};
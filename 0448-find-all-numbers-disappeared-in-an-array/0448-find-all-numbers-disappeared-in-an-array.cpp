class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        int size = nums.size();

        vector <int> answer;

        int i = 0;
        while(i < size)
        {
            int correctIndex = nums[i] -1;
            if(nums[i] != nums[correctIndex])
            {
                swap(nums[i], nums[correctIndex]);
            }
            else
            {
                i++;
            }
        }   

        for(int i = 0; i < size; i++)
        {
            if(nums[i] != i + 1)
            {
                answer.push_back(i + 1);
            }
        } 

        return answer;
    }
};
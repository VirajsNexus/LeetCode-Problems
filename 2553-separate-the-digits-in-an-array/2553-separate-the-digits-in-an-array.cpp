class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) 
    {
        vector<int> answer;

        // Traverse numbers
        for (int index = 0; index < nums.size(); index++) 
        {
            int num = nums[index];
            vector<int> digits;

            // Extract right to left
            while (num > 0) {
                int digit = num % 10;
                digits.push_back(digit);
                num = num / 10;
            }

            // Insert in correct order
            for (int i = digits.size() - 1; i >= 0; i--) {
                answer.push_back(digits[i]);
            }
        }

        return answer;
    }
};
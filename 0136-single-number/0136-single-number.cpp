class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int answer = 0;
        for(int value : nums)
        {
            answer = answer^value ;   // bitwise XOR operator used
        }
        return answer;
    }
};
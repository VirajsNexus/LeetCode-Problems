class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        //variable to store answer
        string answer = "";

        //Hint: use nested loop
        for (int i =0; i< strs[0].size(); i++)      //loop for each character position in the first string
        {
            for (int j = 0; j < strs.size(); j++)   //loop for each string in the array/vector to compare the i-th character
            {
                if (strs[j][i] != strs[0][i])       //imp comparison of prefixes between strings
                                                    //if prefix not matches then return the answer
                                                    //either continue loop for next character
                {
                    return answer;
                }
            }
            answer += strs[0][i];
        }
        return answer;
    }
};
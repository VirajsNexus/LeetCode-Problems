class Solution {
public:
    string multiply(string num1, string num2) 
    {
        //edge case 
        if(num1 =="0" || num2 == "0")
            return "0";

        int length1 = num1.size();
        int length2 = num2.size();

        //initializing vector with size maximum possible digits(length1 + length2)
        vector<int> result(length1 + length2 , 0);

        //multiplyting each digit of num1 with each digit of num2 
        for(int i= length1 -1; i >= 0; --i)
        {
            int digit1 = num1[i] - '0';         //char to int

            for(int j = length2 -1; j >= 0; --j)
            {
                int digit2 = num2[j] - '0';

                //multiplying and adding its result to corresponding position
                result[i + j + 1] += digit1 * digit2;
            }
        }

        //Handle carries (right to left)
        for(int i = result.size() -1; i > 0; --i)
        {
            result[i -1] += result[i] / 10;     //adding carry to previous position
            result[i] %= 10;                    //keep last digit only
        }

        //leading zero case (if present)
        int StartIndex = result[0] == 0 ? 1 : 0;

        //final string
        string answer;
        for(int i =  StartIndex; i < result.size(); ++i)
        {
            answer += '0' + result[i];      //int to char and append
        }

        return answer;
    }
};
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) 
    {
        vector<int> result;
        string digits = "123456789";

        int lowLength = to_string(low).length();
        int highLength = to_string(high).length();

        for(int len = lowLength; len <= highLength; len++)
        {
            for(int start = 0; start <= 9 - len; start++)
            {
                int num = stoi(digits.substr(start, len));
                
                if(num >= low && num <= high)
                {
                    result.push_back(num);
                }
            }
        }
        return result;
    }
};
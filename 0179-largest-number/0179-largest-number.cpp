class Solution {
public:
    string largestNumber(vector<int>& nums) 
    {
        vector<string> array;

        for(int x : nums)
        {
            array.push_back(to_string(x));
        }    
        sort(array.begin(), array.end(), [](string a, string b) {
            return a + b > b + a;
        });

        if(array[0] == "0")
        {
            return "0";
        }

        string result = "";

        for(string s : array)
        {
            result += s;
        }

        return result;
    }
};
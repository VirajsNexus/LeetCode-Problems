class Solution {
public:
    string removeStars(string s) 
    {
        string result;
        for(char character : s)
        {
            if(character == '*')
            {
                result.pop_back();
            }
            else
            {
                result.push_back(character);
            }
        }    
        return result;
    }
};
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) 
    {
        int count = 0;

        for(string s : patterns)
        {
            for(int i = 0; i <= (int)word.size() - (int)s.size(); i++)
            {
                if(word.substr(i, s.size()) == s)
                {
                    count++;
                    break;
                }
            }
        }
        return count;
    }

};
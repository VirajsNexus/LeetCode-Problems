class Solution {
public:
    string truncateSentence(string s, int k) 
    {
        int spaceCount = 0;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == ' ')
            {
                spaceCount++;
            }
            
            // When we have found k words
            if(spaceCount == k)
            {
                return s.substr(0, i);
            }
        }
        
        // If k equals total words, return full string
        return s;
    }
};
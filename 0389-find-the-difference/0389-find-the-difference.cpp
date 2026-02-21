class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != t[i]) 
            {
                return t[i];
            }
        }
        
        // If all characters matched, last character is extra
        return t[t.length() - 1];
    
    }
};
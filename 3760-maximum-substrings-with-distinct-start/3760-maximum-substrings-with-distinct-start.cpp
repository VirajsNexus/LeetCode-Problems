class Solution {
public:
    int maxDistinct(string s) 
    {
        set<char> charSet;

        for(auto i: s)
        {
            charSet.insert(i);
        }    
        return charSet.size();
    }
};
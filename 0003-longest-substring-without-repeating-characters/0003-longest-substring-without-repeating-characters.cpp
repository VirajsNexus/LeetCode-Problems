class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int prev = 0;
        int next = 0;
        int maximumLength = 0;
        set<char>  st;

        while(next < s.length())
        {
            //If character is not in set
            if(st.find(s[next]) == st.end())
            {
                st.insert(s[next]);
                maximumLength = max(maximumLength, next - prev + 1);
                next++;
            }

            //Duplicate element found
            else
            {
                st.erase(s[prev]);
                prev++;
            }
        }

        return maximumLength;
    }
};
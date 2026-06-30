class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int p[3] = {-1, -1, -1};
        int sum = 0;

        for(int i = 0; i < s.length(); i++)
        {
            p[s[i] - 'a'] = i;
            sum = sum + min({p[0], p[1], p[2]}) + 1;
        }
        return sum;
    }
};
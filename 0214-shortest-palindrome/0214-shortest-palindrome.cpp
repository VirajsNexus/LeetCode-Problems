class Solution
{
public:
    vector<int> computeLPS(string pattern)
    {
        int n = pattern.length();
        vector<int> lps(n, 0);

        int len = 0;
        int i = 1;

        while (i < n)
        {
            if (pattern[i] == pattern[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    string shortestPalindrome(string s)
    {
        string rev = s;
        reverse(rev.begin(), rev.end());

        string temp = s + "#" + rev;

        vector<int> lps = computeLPS(temp);

        int longestPrefix = lps.back();

        string add = rev.substr(0, s.length() - longestPrefix);

        return add + s;
    }
};
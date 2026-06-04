class Solution {
public:
    string licenseKeyFormatting(string s, int k) 
    {
        string clean = "";

        // Remove dashes and convert to uppercase
        for (char ch : s) 
        {
            if (ch != '-') 
            {
                clean += toupper(ch);
            }
        }

        string ans = "";
        int count = 0;

        // Build from the end
        for (int i = clean.length() - 1; i >= 0; i--) 
        {
            ans += clean[i];
            count++;

            if (count == k && i != 0) 
            {
                ans += '-';
                count = 0;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
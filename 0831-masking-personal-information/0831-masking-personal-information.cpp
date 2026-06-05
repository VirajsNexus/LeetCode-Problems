class Solution {
public:
    string maskPII(string s) 
    {

        // Email
        if (s.find('@') != string::npos) 
        {
            for (char &c : s)
                c = tolower(c);

            int at = s.find('@');

            return string(1, s[0]) + "*****" +
                   string(1, s[at - 1]) +
                   s.substr(at);
        }

        // Phone Number
        string digits = "";

        for (char c : s) 
        {
            if (isdigit(c))
                digits += c;
        }

        int n = digits.size();
        string last4 = digits.substr(n - 4);

        if (n == 10)
            return "***-***-" + last4;

        string ans = "+" + string(n - 10, '*');
        ans += "-***-***-" + last4;

        return ans;
    }
};
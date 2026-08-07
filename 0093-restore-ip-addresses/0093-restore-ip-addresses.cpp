class Solution {
public:

    void solve(string &s, int index, int parts, string curr, vector<string> &ans)
    {
        // 4 parts completed
        if(parts == 4)
        {
            if(index == s.length())
            {
                curr.pop_back(); // remove last dot
                ans.push_back(curr);
            }
            return;
        }


        // Try length 1 to 3
        for(int len = 1; len <= 3 && index + len <= s.length(); len++)
        {
            string part = s.substr(index, len);

            // leading zero condition
            if(part.length() > 1 && part[0] == '0')
                continue;


            int num = stoi(part);

            // range check
            if(num > 255)
                continue;


            solve(s, index + len, parts + 1, curr + part + ".", ans);
        }
    }


    vector<string> restoreIpAddresses(string s) 
    {
        vector<string> ans;

        solve(s, 0, 0, "", ans);

        return ans;
    }
};
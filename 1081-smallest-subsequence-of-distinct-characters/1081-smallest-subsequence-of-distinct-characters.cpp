class Solution {
public:
    string smallestSubsequence(string s) 
    {
        int freq[26] = {0};

        //count frequency
        for(char ch : s)
            freq[ch - 'a']++;

        bool visited[26] = {false};

        string st = "";

        for(char ch : s)
        {
            freq[ch - 'a']--;

            //already included
            if(visited[ch - 'a'])
                continue;

            //remove larger characters if they appears later
            while(!st.empty() && st.back() > ch && freq[st.back() - 'a'] > 0)
            {
                visited[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(ch);
            visited[ch - 'a'] = true;
        }   
        return st;
    }
};
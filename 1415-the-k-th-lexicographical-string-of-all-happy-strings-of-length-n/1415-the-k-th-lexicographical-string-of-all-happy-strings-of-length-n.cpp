class Solution {
public:
    vector<string> result;

    void generate(string s, int a)
    {
        if(s.length() == a)
        {
            result.push_back(s);
            return;
        }

        for(char ch = 'a'; ch <= 'c'; ch++)
        {
            if(s.length() > 0 && s[s.length() - 1] == ch)
            {
                continue;
            }
            s.push_back(ch);
            generate(s, a);
            s.pop_back();
        }
    }
    string getHappyString(int n, int k) 
    {
        generate("", n);

        if(result.size() < k)
        {
            return "";
        }

        sort(result.begin(), result.end());

        return result[k - 1];
    }
};
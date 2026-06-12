class Solution {
public:
    int repeatedStringMatch(string a, string b) 
    {
        string s = a;
        int count = 1;

        while (s.size() < b.size()) 
        {
            s += a;

            count++;
        }

        int pos = s.find(b);

        if (pos != -1)
            return count;

        s += a;

        pos = s.find(b);

        if (pos != -1)
            return count + 1;

        return -1;
    }
};
class Solution {
public:
    vector<string> result;

    void backTrack(string &current, int open, int close, int size)
    {
        if(current.size() == 2 * size)
        {
            result.push_back(current);
            return;
        }

        //choose '('
        if(open < size)
        {
            current.push_back('(');
            backTrack(current, open + 1, close, size);
            current.pop_back();
        }

        //Choose ')'
       if(close < open)
       {
        current.push_back(')');
        backTrack(current, open, close + 1, size);
        current.pop_back();
       }

    }
    vector<string> generateParenthesis(int n) 
    {
        string current = "";
        backTrack(current, 0, 0, n);
        return result;
    }
};
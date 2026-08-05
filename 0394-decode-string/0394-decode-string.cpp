class Solution {
public:
    string decodeString(string s) 
    {
        stack<int> numStack;
        stack<string> strStack;

        string currStr = "";
        int currNum = 0;

        for (char ch : s) 
        {
            if (isdigit(ch)) 
            {
                currNum = currNum * 10 + (ch - '0');
            }
            else if (ch == '[') 
            {
                numStack.push(currNum);
                strStack.push(currStr);

                currNum = 0;
                currStr = "";
            }
            else if (ch == ']') 
            {
                int repeat = numStack.top();
                numStack.pop();

                string prev = strStack.top();
                strStack.pop();

                while (repeat--) 
                {
                    prev += currStr;
                }

                currStr = prev;
            }
            else 
            {
                currStr += ch;
            }
        }

        return currStr;
    }
};
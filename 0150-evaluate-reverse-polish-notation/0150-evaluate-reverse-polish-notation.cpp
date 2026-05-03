class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack <int> stck;

        for(string token : tokens)
        {
            if(token == "+" || token == "-" || token == "*" || token == "/")
            {
                int last = stck.top();
                stck.pop();
                 
                int first = stck.top();
                stck.pop();

                if(token == "+")
                    stck.push(last + first);
                
                else if(token == "-")
                    stck.push(first - last);
                
                else if(token == "*")
                    stck.push(first * last);
                
                else 
                    stck.push( first / last);
            }
            else
            {
                stck.push(stoi(token));
            }
        }    
        return stck.top();
    }
};
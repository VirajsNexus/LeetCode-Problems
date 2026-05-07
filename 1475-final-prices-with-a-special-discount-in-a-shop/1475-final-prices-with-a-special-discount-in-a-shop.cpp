class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) 
    {
        int size = prices.size();

        stack<int> stck;

        for(int i = 0; i < size; i++)
        {
            //find discount
            while(!stck.empty() && prices[stck.top()] >= prices[i])
            {
                prices[stck.top()] -= prices[i];
                stck.pop();
            }
            stck.push(i);
        }    
        return prices;
    }
};
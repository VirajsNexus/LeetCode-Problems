class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int minPrice = prices[0];
        int size = prices.size();
        int profit = 0;

        for(int i = 1; i < size; i++)
        {
            if(prices[i] < minPrice)
            {
                minPrice = prices[i];
            }
            else
            {
                if(profit < (prices[i] - minPrice))
                {
                    profit = prices[i] - minPrice;
                }
            }
        }
        return profit;
    }
};
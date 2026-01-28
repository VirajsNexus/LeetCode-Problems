class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) 
    {
        int Time = 0;


        //iterating queue
        for(int i = 0; i< tickets.size(); ++i)
        {
            // Logic: People at or before kth position can buy tickets[k] tickets 
            //for people after k can buy tickets[k] -1 most
            //Hence kth person will leave after buying his last ticket

            // Case 1: peoples at position k and before
            if(i <= k)
            {
                Time += min(tickets[i], tickets[k]);
            }

            // Case 2: Peoples after kth position
            else
            {
                Time += min(tickets[i], tickets[k] -1);
            }
        }    
        return Time;
    }
};
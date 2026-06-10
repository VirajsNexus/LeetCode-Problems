class Solution {
public:

    vector<vector<int>> dp;
    int solve(int i, int time, vector<int> &sat)
    {
        if(i == sat.size())   
            return 0;
        
        if(dp[i][time] != -1)
            return dp[i][time];
        
        int take = sat[i] * time + solve(i + 1, time + 1, sat);

        int skip = solve(i + 1, time, sat);

        return dp[i][time] = max(take, skip);

    }
    int maxSatisfaction(vector<int>& satisfaction) 
    {
        sort(satisfaction.begin(), satisfaction.end());

        int size = satisfaction.size();

        dp.assign(size + 1, vector<int>(size + 2, -1));

        return solve(0, 1, satisfaction);
    }
};
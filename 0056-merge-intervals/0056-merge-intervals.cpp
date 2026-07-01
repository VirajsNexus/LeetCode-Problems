class Solution {
public:
        static bool compare(vector<int> a, vector<int> b)
        {
            return a[0] < b[0];
        }

    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end(), compare);

        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++)
        {
            int lastIndex = result.size() - 1;
            //checking overlapping
            if(intervals[i][0] <= result[lastIndex][1])
            {
                //update ending point if needed
                if(intervals[i][1] > result[lastIndex][1])
                {
                    result[lastIndex][1] = intervals[i][1];
                }
            }
            else
            {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};
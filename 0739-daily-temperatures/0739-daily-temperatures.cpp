class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int size = temperatures.size();

        vector<int> answer(size, 0);

        stack<int> stck;

        for(int i = 0; i < size; i++)
        {
            //find warm day
            while(!stck.empty() && temperatures[i] > temperatures[stck.top()])
            {
                int index = stck.top();
                stck.pop();

                answer[index] = i - index;
            }
            stck.push(i);
        }
        return answer;
    }
};
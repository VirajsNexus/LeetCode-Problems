class Solution 
{
public:
    int closestTarget(vector<string>& words, string target, int startIndex) 
    {
        int size = words.size();
        int ans = INT_MAX;

        for(int i = 0; i < size; i++)
        {
            if(words[i] == target)
            {
                int difference = abs(i - startIndex);       // 'abs()' to convert number into non-negative
                int distance;

                if(difference < size - difference)
                    distance = difference;
                else
                    distance = size - difference;

                if(distance < ans)
                    ans = distance;
            } 
        }

        if(ans == INT_MAX)
            return -1;
        else
            return ans;
    }
};
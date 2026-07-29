class Solution {
public:
    long long sumScores(string s) 
    {
        int size = s.size();
        vector<int> z(size, 0);

        int l = 0, r = 0;

        for (int i = 1; i < size; i++) 
        {
            if (i <= r)
                z[i] = min(r - i + 1, z[i - l]);

            while (i + z[i] < size && s[z[i]] == s[i + z[i]])
                z[i]++;

            if (i + z[i] - 1 > r) 
            {
                l = i;
                r = i + z[i] - 1;
            }
        }

        long long ans = size;

        for (int i = 1; i < size; i++)
            ans += z[i];

        return ans;
    }
};
class Solution
{
public:
    vector<int> getStrongest(vector<int>& arr, int k)
    {
        sort(arr.begin(), arr.end());

        int n = arr.size();

        int m = arr[(n - 1) / 2];

        sort(arr.begin(), arr.end(), [m](int a, int b)
        {
            int strengthA = abs(a - m);
            int strengthB = abs(b - m);

            if (strengthA == strengthB)
                return a > b;

            return strengthA > strengthB;
        });

        vector<int> ans;

        for (int i = 0; i < k; i++)
        {
            ans.push_back(arr[i]);
        }

        return ans;
    }
};
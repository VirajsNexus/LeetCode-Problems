class Solution 
{
public:

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) 
    {

        vector<string> prefixes;

        // Store all prefixes from arr1
        for (int num : arr1) 
        {

            string s = to_string(num);
            string temp = "";

            for (char ch : s) 
            {
                temp += ch;
                prefixes.push_back(temp);
            }
        }

        // Sort for binary search
        sort(prefixes.begin(), prefixes.end());

        int ans = 0;

        // Check prefixes from arr2
        for (int num : arr2) 
        {

            string s = to_string(num);
            string temp = "";

            for (char ch : s) 
            {

                temp += ch;

                // Binary search
                if (binary_search(prefixes.begin(), prefixes.end(), temp)) 
                {
                    ans = max(ans, (int)temp.length());
                }
            }
        }

        return ans;
    }
};
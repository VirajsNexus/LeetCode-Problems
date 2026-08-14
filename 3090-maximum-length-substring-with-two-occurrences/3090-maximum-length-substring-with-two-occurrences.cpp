class Solution {
public:
    int maximumLengthSubstring(string s) 
    {
       int iFrequency[26] = {};
       int left = 0;
       int right;
       int result = 0;

       for (right = 0; right < s.length(); right++)
       {
            iFrequency[s[right] - 'a']++;

            while(iFrequency[s[right] - 'a'] > 2)
            {
                iFrequency[s[left] - 'a']--;
                left++;
            }
            result = max(result, right - left + 1);
       }
       return result;
    }
};
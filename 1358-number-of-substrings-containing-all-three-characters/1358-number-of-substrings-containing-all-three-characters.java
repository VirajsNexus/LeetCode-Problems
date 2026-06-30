class Solution {
    public int numberOfSubstrings(String s) 
    {   
        int[] p = {-1, -1, -1};
        int sum = 0;

        for(int i = 0; i < s.length(); i++)
        {
            p[s.charAt(i) - 'a'] = i;
            sum = sum + Math.min(p[0], Math.min(p[1], p[2])) + 1;
        }    
        return sum;
    }
}
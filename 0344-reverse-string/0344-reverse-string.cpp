class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        //swapping logic can be used here
        int leftChar = 0;
        int rightChar =s.size() -1;

        //lets swao elments untill they meets at meedle
        while(leftChar < rightChar)
        {
            swap(s[leftChar], s[rightChar]);

            //moving left pointer backward and right pointer forward
            leftChar++;
            rightChar--;
        }
    }
};
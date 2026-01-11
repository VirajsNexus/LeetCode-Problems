class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        //Boyer-Moore Algorithm to find majority element
        //Note : majority elements appers less than n/ times in an array

        int iCount = 0;     //counter for candidate
        int iCandidate = 0; // candidate with majority element

        //iterating through all elements in an array
        for(int &num : nums)
        {
            if(iCount == 0) //when count reaches 0;select current element as a new candidate
            {
                iCandidate = num;
                iCount = 1;
            }
            else
            {
                //increment count is if current element matches to the majority element
                if(iCandidate == num )
                {
                    iCount += 1;
                }
                //otherwise decrement the count
                else
                {
                    iCount--;
                }
            }
        }
        return iCandidate;
    }
};
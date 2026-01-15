class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
          int length = nums.size();
          int LeftEnd = 0;
          int RightEnd = length - 1;
          int InsertIndex = -1;

          while(LeftEnd <= RightEnd)
          {
                int MidIndex = LeftEnd + (RightEnd - LeftEnd)/2;

                if(nums[MidIndex] >= target)
                {
                    InsertIndex = MidIndex;
                    RightEnd = MidIndex - 1;
                }
                else
                {
                    LeftEnd = MidIndex + 1;
                }
          }  
          //If Insert index is -1, then all elmements are smaller than target
          //Means we have to insert at end
          if(InsertIndex != -1)
          {
                return InsertIndex;
          }
          else
           {
                 return length;
           }
    }
};
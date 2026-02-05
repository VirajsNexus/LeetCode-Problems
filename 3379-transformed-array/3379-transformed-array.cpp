class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) 
    {
            int size = nums.size();
            vector<int> result(size);

            for(int i =0; i< size; i++)
            {
                //if current element is 0, then result at index i will be 0
                if(nums[i] == 0)
                    result[i] = 0;
                
                else
                {
                    //taret index by circular array handling 
                    int targetIndex = getCircularIndex(i, nums[i], size);
                    result[i] = nums[targetIndex];
                }
            }
            return result;
    }
        private:
            int getCircularIndex(int currentPos, int moveBy, int size) 
            {
                // 1. Remove extra full laps
                int effectiveMove = moveBy % size;
        
                // 2. Add 'size' to handle jumps that go backwards (negative)
                int rawTarget = currentPos + effectiveMove + size;
        
                // 3. Final wrap to stay within array bounds
                return rawTarget % size;
            }
};
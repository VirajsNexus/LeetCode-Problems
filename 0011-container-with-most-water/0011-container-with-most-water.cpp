class Solution {
public:
    int maxArea(vector<int>& height) 
    {   
        
        int maxWater = 0;
        
        //using two pointers logic
        int leftIndex = 0;
        int rightIndex = height.size() - 1;

        while(leftIndex < rightIndex)
        {   
            int left = height[leftIndex];
            int right = height[rightIndex]; 

            int area = min(left, right) * (rightIndex - leftIndex);     // Area calculation
            maxWater = max(maxWater, area);

            if(left < right)
                leftIndex++;
            else
                rightIndex--;            
        }

        return maxWater;
    }
};
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) 
    {
        int a = nums1.length;
        int b = nums2.length;

        int[] merged = new int[a + b];

        int i = 0;
        int j = 0;
        int k = 0;

        while(i < a && j < b)
        {
            if(nums1[i] <= nums2[j])
            {
                merged[k++] = nums1[i++]; 
            }
            else
            {
                merged[k++] = nums2[j++];
            }
        }

        while(i < a)
        {
            merged[k++] = nums1[i++];
        }
        
        while(j < b)
        {
            merged[k++] = nums2[j++];
        }

        int size = a + b;

        if(size % 2 == 1)
        {
            return merged[size / 2];
        }
        else
        {
            return (merged[size / 2 - 1] + merged[size / 2]) / 2.0;
        }

    }
}
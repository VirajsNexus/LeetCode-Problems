class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
         // Initialize three pointers:
        // First : points to the last valid element in nums1's original part
        // Second: points to the last element in nums2
        // Third: points to the last position in the merged array
        int First = m - 1;
        int Second = n - 1;
        int Third = m + n - 1;
      
        // Continue merging while there are elements in nums2 to process
        while (Second >= 0) {
            // Compare elements from both arrays and place the larger one at position First
            // If nums1 has elements left (First >= 0) and nums1[First] is greater than nums2[Second],
            // place nums1[First] at position k and decrement First
            // Otherwise, place nums2[j] at position Third and decrement Second
            if (First >= 0 && nums1[First] > nums2[Second]) {
                nums1[Third] = nums1[First];
                First--;
            } else {
                nums1[Third] = nums2[Second];
                Second--;
            }
            Third--;
        }
        // Note: If elements remain in nums1 after nums2 is exhausted,
        // they are already in their correct positions
    }
};
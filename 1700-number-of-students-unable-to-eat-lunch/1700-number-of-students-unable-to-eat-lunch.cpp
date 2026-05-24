class Solution 
{
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) 
    {
        int count0 = 0, count1 = 0;

        // Count student preferences
        for (int s : students) 
        {
            if (s == 0)
                count0++;
            else
                count1++;
        }

        // Process sandwiches
        for (int sandwich : sandwiches)
        {
            if (sandwich == 0) 
            {
                if (count0 == 0)
                    return count1; // remaining students
                count0--;
            } 
            else 
            {
                if (count1 == 0)
                    return count0; // remaining students
                count1--;
            }
        }

        return 0;
    }
};
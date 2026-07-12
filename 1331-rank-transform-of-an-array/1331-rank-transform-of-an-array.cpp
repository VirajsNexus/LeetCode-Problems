class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) 
    {
        vector<int> temp = arr;

        //sort original array
        sort(temp.begin(), temp.end());

        map<int, int> rank;
        int currentRank = 1;

        for(int i = 0; i < temp.size(); i++)
        {
            if(rank.find(temp[i]) == rank.end())    
            {
                rank[temp[i]] = currentRank;
                currentRank++;
            }
        }    

        //replace rank wrt their original elements
        for(int i = 0; i < arr.size(); i++)
        {
            arr[i] = rank[arr[i]];
        }

        return arr;
    }
};
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) 
    {   
        vector <int> answer(n, 0);
        stack <int> stck;
        int previous = 0;

        for(string s : logs)
        {
            int i = 0;
            int id = 0;

            //get id
            while(s[i] != ':')
            {
                id = id * 10 + (s[i] - '0');
                i++;
            }
            i++;                            //skip

            //get type
            string type = "";
            while(s[i] != ':')
            {
                type += s[i];
                i++;
            }
            i++;                            //skip

            //get time
            int time = 0;
            while(i < s.size())
            {
                time = time * 10 + (s[i] - '0');
                i++;
            }

            if(type == "start")
            {
                if(!stck.empty())
                {
                    answer[stck.top()] += time - previous;
                }
                stck.push(id);
                previous = time;
            }
            else
            {
                answer[stck.top()] += time - previous + 1;
                stck.pop();
                previous = time + 1;
            }
        }
        return answer;
    }
};
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) 
    {
        vector<string> result;
      
        // Get the total number of words in the input vector
        int wordCount = words.size();
      
        // Iterate through each word as a potential substring
        for (int i = 0; i < wordCount; ++i) {
            // Check if current word is a substring of any other word
            for (int j = 0; j < wordCount; ++j) {
                // Skip if comparing the same word with itself
                // Check if words[i] is a substring of words[j]
                if (i != j && words[j].find(words[i]) != string::npos) {
                    // Found words[i] as substring, add to result
                    result.push_back(words[i]);
                    // Break inner loop as we only need to add once
                    break;
                }
            }
        }
      
        return result;

    }
};
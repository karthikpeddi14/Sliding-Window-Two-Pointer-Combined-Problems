class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int left=0;
        int right=0;
        int maxLen = 0;
        map<char,int> charindex;

        for(int i=0 ; i<s.size() ; i++)
        {
            if(charindex.find(s[i])!= charindex.end() && charindex[s[i]]>=left)
            {
                left = charindex[s[i]]+1;
                charindex.erase(s[i]);
            }
            charindex[s[i]] = i;
            maxLen = max(maxLen,right-left+1);
            right++;
        }
        return maxLen;
    }
};

class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int start=0 , end=0, count=0;
        int sum[3] = {0};
        int alln = 0;
        int n = s.size();

        while(end<n)
        {
            sum[s[end]-'a']++;
            if(sum[s[end]-'a']==1) alln++;
            
            while(start<end && alln==3)
            {
                count += n-end;
                sum[s[start]-'a']--;
                if(sum[s[start]-'a']==0)alln--;
                start++;
            }
            end++;
        }
        return count;
    }
};

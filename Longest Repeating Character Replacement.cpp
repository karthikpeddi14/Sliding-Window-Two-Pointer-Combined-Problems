class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int ans =1;
        for(int i=0 ; i<26 ; i++)
        {
            char temp = 'A'+i;
            string con;
            con = con+temp;
            if(s.find(con)<0 || s.find(con)>=s.size()) continue;

            int left = 0;
            int right = 0;
            int kcopy = k;
            vector<int> v;
            // while(right<s.size() && s[right]!=temp) 
            // {
            //     left++ ; 
            //     right++;
            // }
            // if(s[right]==temp) right++;
            // else if(k!=0)
            // {
            //     kcopy--;
            //     v.push_back(right);
            //     right++;
            // }
            while(right<s.size())
            {
                if(s[right]==temp) right++;
                else if(k==0)
                {
                    while(right<s.size() && s[right]!=temp) right++;
                    left = right;
                    right++;
                }
                else if(kcopy>0) 
                {
                    kcopy--;
                    v.push_back(right);
                    right++;
                }
                else 
                {
                    left = v[0]+1;
                    kcopy++;
                    v.erase(v.begin());
                }
                ans = max(ans,right-left);
            }
        }
        return ans;
    }
};
                //  right = temp , right++;
                // not equal -> k>0 , k=0;
                // k>0 -> vector push and  k--;
                // k=0 -> left = k+1, k++;

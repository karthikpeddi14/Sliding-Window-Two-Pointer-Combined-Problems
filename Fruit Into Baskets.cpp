class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) 
    {
        pair<int,int> type1 = {-1,-1};
        pair<int,int> type2 = {-1,-1};
        int count1 =0;
        int count2 =0;
        int ans = 0;
        
        for(int i=0 ; i<fruits.size() ; i++)
        {
            if(fruits[i]==type1.first || type1.first==-1)
            {
              count1++;
              type1.first = fruits[i];
              type1.second = i;
            }
            else if(fruits[i] == type2.first || type2.first == -1)
            {
                count2++;
              type2.first = fruits[i];
              type2.second = i;
            }
            else
            {
                if(type1.second>type2.second)
                {
                    count1 = type1.second-type2.second;
                    type2.first = fruits[i];
                    type2.second = i;
                    count2 = 1;
                }
                else
                {
                    count2 = type2.second-type1.second;
                    type1.first = fruits[i];
                    type1.second = i;
                    count1 = 1;
                }
            }
            
           ans =  max(ans, count1+count2);
        }
        return ans;
    }
};

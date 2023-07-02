class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int left = 0;
        int right = 0;
        vector<int> zero_index;
        int ans = 0;

        for(int i=0 ; i<nums.size() ; i++)
        {
            if(nums[i]==0)
            {
                if(k==0) left = i+1;
                else if(zero_index.size()==k)
                {
                    left = zero_index[0]+1;
                    zero_index.erase(zero_index.begin());
                }
                zero_index.push_back(i);
            }
            ans = max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};

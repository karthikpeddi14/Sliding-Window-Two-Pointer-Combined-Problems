class Solution {
public:
    int atmostgoal(vector<int>& nums , int goal)
    {
        int start =0 , end = 0, count = 0;
        int sum = 0;
        while(end<nums.size())
        {
            sum = sum + nums[end];
            end++;
            while(start<end && sum>goal) sum -= nums[start++];
            count += end-start;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        return atmostgoal(nums,goal) - atmostgoal(nums,goal-1);
    }
};

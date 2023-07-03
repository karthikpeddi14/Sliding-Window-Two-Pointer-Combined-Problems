class Solution {
public:
    int atmostkodd(vector<int> & nums , int k)
    {
        int start = 0, end = 0, count = 0;
        int odd_count = 0;

        while(end<nums.size())
        {
            if(nums[end]%2) odd_count++;
            end++;
            while(start<end && odd_count >k ) 
            {
                if(nums[start]%2) odd_count--;
                start++;
            } 
            count += end-start;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        return atmostkodd(nums,k) - atmostkodd(nums,k-1);
    }
};

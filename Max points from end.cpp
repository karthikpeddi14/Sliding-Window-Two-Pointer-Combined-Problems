class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        int total_sum = 0;
        int n = cardPoints.size();
        int slider_sum = 0;
        for(int i=0 ; i<n ; i++)
        {
            total_sum += cardPoints[i];
            if(i==n-k-1) slider_sum = total_sum; 
        }

        int mini=slider_sum;
        int start = 0;
        int end = n-k;
        while(end<n)
        {
            slider_sum = slider_sum - cardPoints[start] + cardPoints[end];
            end++;
            start++;
            mini = min(mini,slider_sum);
        }
        return total_sum - mini;

    }
};

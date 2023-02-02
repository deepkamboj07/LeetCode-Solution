class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum=0;
        for(auto it: nums)
            sum+=it;
        
        int sum2=0;
        for(auto it: nums)
        {
            while(it)
            {
                int digit=it%10;
                sum2+=digit;
                it/=10;
            }
        }
        
        return abs(sum-sum2);
    }
};
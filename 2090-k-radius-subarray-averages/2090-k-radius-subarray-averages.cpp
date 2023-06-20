class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int j=0,i=0;
        int n=nums.size();
        vector<int> ans(n,-1);
        long long int sum=0;
        
        while(j<n)
        {
            sum+=nums[j];
            if(j-i+1==(k*2)+1)
            {
                int mid=k;
                int avg=sum/(j-i+1);
                ans[i+mid]=avg;
                
                sum-=nums[i];
                i++;
            }
            j++;
        }
        
        return ans;
    }
};
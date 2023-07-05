class Solution {
public:

    int longestSubarray(vector<int>& nums) {
        int i=0;
        int j=0,n=nums.size();
        int count=0,ans=0,del=0;
        while(j<n)
        {
            if(nums[j]==0)
            {
               if(del==1)
               {
                   ans=max(ans,count);
                   del=1;
                   count=(j-i)-1;
                   i=j;
               }
               else
               {
                   i=j;
                   del=1;
               }
            }
            else
            {
                count++;
            }
            
            j++;
        }
        
        ans=max(ans,count);
        
        if(ans==n)return ans-1;
        return ans;
    }
};
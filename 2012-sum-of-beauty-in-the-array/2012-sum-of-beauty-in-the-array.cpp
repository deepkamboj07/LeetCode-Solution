class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix_max(n,0),suffix_min(n,0);
        
        prefix_max[0]=nums[0];
        for(int i=1;i<n;i++)
            prefix_max[i]=max(prefix_max[i-1],nums[i]);
        
        
        suffix_min[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffix_min[i]=min(suffix_min[i+1],nums[i]);
        }
        
        
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
            int num=nums[i];
            if(prefix_max[i-1]<num and suffix_min[i+1]>num)
            {
                ans+=2;
            }
            else if(num > nums[i-1] and num < nums[i+1])
            {
                ans+=1;
            }
        }
        
        return ans;
    }
};
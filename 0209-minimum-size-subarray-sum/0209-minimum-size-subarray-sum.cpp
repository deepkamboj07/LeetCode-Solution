class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int i=0,j=0;
        int n=nums.size();
        int sum=0;
        int mini=1e9;
        
        while(j<n)
        {
            sum+=nums[j];
            while(i<=j and sum >= target)
            {
                mini=min(mini, j-i+1);
               // cout<<mini<<"  -> "<<i<<" "<<j<<endl;
                sum-=nums[i];
                i++;
            }
            j++;
        }
        cout<<endl<<endl;
        return (mini==1e9)?0:mini;
    }
};
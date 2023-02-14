class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0,j=0;
        int prev=-1e9;
        int count=1,n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==prev)
            {
                count++;
                if(count>=3)
                {
                    prev=nums[i];
                    continue;
                }
            }
            else
            {
                count=1;
            }
            nums[j]=nums[i];
            prev=nums[i];
            j++;
        }
        
        return j;
    }
};
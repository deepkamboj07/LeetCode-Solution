class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        
        int n=nums.size();
        int i=0,j=0;
        multiset<int> ms;
        vector<int> ans;
        
        while(j<n)
        {         
            if((j-i)+1 < k)
            {
                if(nums[j]<0)ms.insert(nums[j]);
            }
            else if((j-i)+1 == k)
            {
                if(nums[j]<0)ms.insert(nums[j]);
                if(ms.size()<x)ans.push_back(0);
                else
                {
                    ans.push_back(*next(ms.begin(),(x-1)));
                }
                
                if(nums[i]<0)ms.erase(ms.find(nums[i]));
                i++;
            }
            j++;
        }       
        
        return ans;
    }
};
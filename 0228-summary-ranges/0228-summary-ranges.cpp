class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n=nums.size();
        if(n==0)return {};
        
        int prev=nums[0];
        string tmp=to_string(prev);
        for(int i=1;i<n;i++)
        {
            if(prev+1==nums[i])
            {
                prev=nums[i];
                continue;
            }
            else
            {
                if(tmp!=to_string(prev))
                {   tmp+="->";
                    tmp+=to_string(prev);
                }
                ans.push_back(tmp);
                prev=nums[i];
                tmp=to_string(prev);
            }
        }
        
        if(tmp!=to_string(prev))
        {   tmp+="->";
            tmp+=to_string(prev);
        }
        
        ans.push_back(tmp);
        return ans;
        
    }
};
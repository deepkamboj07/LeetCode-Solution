class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n=nums.size();
        int i=0,j=0;
        
        vector<int> ans;
        deque<int> dq;
      
        if(k>=n)
        {
            ans.push_back(*max_element(nums.begin(),nums.end()));
            return ans;
        }

        while(j<n)
        {
            while(dq.size()>0 and dq.back() < nums[j])
                dq.pop_back();
            
            dq.push_back(nums[j]);
            if(j-i+1<k)
            {
                j++;
            }
            else
            { 
                ans.push_back(dq.front());
                
                if(nums[i]==dq.front())
                    dq.pop_front();
                
                i++;
                j++;
            }
        }
        return ans;
    }
};
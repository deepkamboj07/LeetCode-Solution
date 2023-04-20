class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        priority_queue<int> odd;
        priority_queue<int,vector<int>,greater<int>> even;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            int it=nums[i];
            if(i%2==0)
                even.push(it);
            else 
                odd.push(it);
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
           if(i%2==0)
           {
               ans[i]=even.top();
               even.pop();
           }
           else
            {
                ans[i]=odd.top();
                odd.pop();
            }
        }
        
        return ans;
    }
};